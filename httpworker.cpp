#include "httpworker.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonArray>

void HttpWorker::setHost(QString addr)
{
    host = addr;
}

void HttpWorker::setPort(int value)
{
    port = value;
}

QString HttpWorker::getHost()
{
    return host;
}

int HttpWorker::getPort()
{
    return port;
}

HttpWorker::HttpWorker(QJsonDocument doc, QString service, QObject *parent) : QThread(parent), errorException("")
{
    this->url.setScheme("http");
    this->url.setHost(host);
    this->url.setPort(port);
    this->url.setPath(service);
    this->sentJson = doc;
    this->error = false;
}

void HttpWorker::run()
{
    if(isJsonEmpty()) {
        setError("Empty json document.");
        return;
    }

    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager.post(request, sentJson.toJson());

    loop.exec();

    receivedJson = QJsonDocument::fromJson(reply->readAll());

    if(reply->error() != QNetworkReply::NetworkError::NoError) {
        setError(reply->errorString() + '\n' + jsonErrorsToString());
    }
}

QString HttpWorker::jsonErrorsToString()
{
    QJsonObject root = receivedJson.object();
    QJsonArray errorsTypes = root["errors"].toArray();

    QString str;
    for(auto val: errorsTypes) {
        str += '-' + val.toString() + '\n';
    }

    return str;
}

void HttpWorker::setError(const QString &msg)
{
    errorException = std::runtime_error(msg.toLatin1());
    error = true;
}

bool HttpWorker::isJsonEmpty() const
{
    return  (sentJson["title"].isUndefined()? false : sentJson["title"].toString().isEmpty()) ||
            (sentJson["systemActor"].isUndefined()? false : sentJson["systemActor"].toString().isEmpty()) ||
            (sentJson["steps"].isUndefined()? false : sentJson["steps"].toArray().isEmpty()) ||
            (sentJson["scenario"].isUndefined()? false : sentJson["scenario"].toObject().isEmpty());
}

QJsonDocument HttpWorker::getResponse()
{
    if(error) {
        error = false;
        throw errorException;
    } else {
        return receivedJson;
    }
}
