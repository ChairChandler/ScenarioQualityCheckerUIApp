#ifndef HTTPWORKER_H
#define HTTPWORKER_H
#pragma GCC diagnostic ignored "-Wc++17-extensions"
#pragma GCC diagnostic ignored "-Wpadded"

#include <QThread>
#include <QUrl>
#include <QJsonDocument>

class HttpWorker : public QThread
{
    Q_OBJECT
    static inline QString host;
    static inline int port;
    QUrl url;
    QJsonDocument receivedJson, sentJson;
    std::runtime_error errorException;
    bool error;

    QString jsonErrorsToString();
    void setError(const QString &msg);
    bool isJsonEmpty() const;
public:
    static void setHost(QString addr);
    static void setPort(int value);
    static QString getHost();
    static int getPort();
    explicit HttpWorker(QJsonDocument doc, QString service, QObject *parent = nullptr);
    void run() override;
    QJsonDocument getResponse();
};

#endif // HTTPWORKER_H
