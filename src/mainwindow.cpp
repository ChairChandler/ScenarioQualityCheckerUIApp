#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpworker.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(appName);

    HttpWorker::setHost("localhost");
    HttpWorker::setPort(8080);

    connect(ui->actionCount_steps, &QAction::triggered,
            this, &MainWindow::httpRequestCountSteps);

    connect(ui->actionCut_to_depth, &QAction::triggered,
            this, &MainWindow::httpRequestCutToDepth);

    connect(ui->actionCount_keywords, &QAction::triggered,
            this, &MainWindow::httpRequestCountKeywords);

    connect(ui->actionFind_lines_not_starting_with_an_actor, &QAction::triggered,
            this, &MainWindow::httpRequestFindLinesNotStartingWithAnActor);

    connect(ui->actionGenerate_numbered_list, &QAction::triggered,
            this, &MainWindow::httpRequestGenerateNumberedList);

    connect(ui->actionLoad_JSON2, &QAction::triggered,
            this, &MainWindow::loadJSON);

    connect(ui->addPushButton, &QPushButton::clicked,
            this, &MainWindow::addActor);

    connect(ui->removePushButton, &QPushButton::clicked,
            this, &MainWindow::removeActor);

    connect(ui->actionHost, &QAction::triggered,
            this, &MainWindow::setHost);

    connect(ui->actionPort, &QAction::triggered,
            this, &MainWindow::setPort);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::httpRequestCountSteps()
{
    HttpWorker *worker = new HttpWorker(createJsonFromWidgets(), "/api/scenario/steps/count");
    connect(worker, &HttpWorker::finished, this, [&, worker](){
        try {
            QJsonDocument doc = worker->getResponse();
            QMessageBox::information(this, "Results", "Count: " + QString::number(doc["count"].toInt()));
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Count steps error", e.what());
        }

        delete worker;
    });
    worker->start();
}

void MainWindow::httpRequestCountKeywords()
{    
    HttpWorker *worker = new HttpWorker(createJsonFromWidgets(), "/api/scenario/keywords/count");
    connect(worker, &HttpWorker::finished, this, [&, worker](){
        try {
            QJsonDocument doc = worker->getResponse();
            QMessageBox::information(this, "Results", "Count: " + QString::number(doc["count"].toInt()));
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Count keywords error", e.what());
        }

        delete worker;
    });
    worker->start();
}

void MainWindow::httpRequestFindLinesNotStartingWithAnActor()
{    
    HttpWorker *worker = new HttpWorker(createJsonFromWidgets(), "/api/scenario/steps/not-starting-with-actor");
    connect(worker, &HttpWorker::finished, this, [&, worker](){
        try {
            QJsonDocument doc = worker->getResponse();

            QString msg;
            for(auto line: doc["lines"].toArray()) {
                msg += '-' + line.toString() + '\n';
            }

            QMessageBox::information(this, "Results", "Lines:\n" + msg);
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Find lines error", e.what());
        }

        delete worker;
    });
    worker->start();
}

void MainWindow::httpRequestCutToDepth()
{
    auto [json, success] = addDepthLevel(createJsonFromWidgets());
    if(!success) {
        return;
    }

    HttpWorker *worker = new HttpWorker(json, "/api/scenario/cut-to-depth");
    connect(worker, &HttpWorker::finished, this, [&, worker](){
        try {
            QJsonDocument doc = worker->getResponse();
            QMessageBox::information(this, "Results", doc.toJson());
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Cut to depth error", e.what());
        }

        delete worker;
    });
    worker->start();
}

void MainWindow::httpRequestGenerateNumberedList()
{
    HttpWorker *worker = new HttpWorker(createJsonFromWidgets(), "/api/scenario/numbered-steps");
    connect(worker, &HttpWorker::finished, this, [&, worker](){
        try {
            QJsonDocument doc = worker->getResponse();
            QMessageBox::information(this, "Results", doc["numbered-steps"].toString());
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Cut to depth error", e.what());
        }

        delete worker;
    });
    worker->start();
}

void MainWindow::loadJSON()
{
    QString url = QFileDialog::getOpenFileUrl(this, "Select JSON file", QDir().path(), "JSON (*.json)").toLocalFile();
    if(!url.isEmpty()) {
        QByteArray array;
        QFile file(url);
        using Fs = QFile::OpenModeFlag;
        if(!file.open(QFile::OpenMode(Fs::ReadOnly|Fs::Text))) {
            QMessageBox::warning(this, "File loading error", "Couldn't load selected JSON file!");
            return;
        }

        QByteArray jsonData;
        QTextStream fs(&file);

        jsonData.clear();
        jsonData.append(fs.readAll());

        file.close();
        setJsonToWidgets(QJsonDocument::fromJson(jsonData));
    } else {
        QMessageBox::warning(this, "No JSON file selected", "Selecting JSON file was cancelled, "
                                                            "text from app will be sent.");
    }
}

void MainWindow::addActor()
{
    bool actorExists = false, ok;
    QString begMsg = "Actor name exists, select another name.\n";

    forever {
        QString name = QInputDialog::getText(this, "New actor", (actorExists? begMsg: QString()) + "Actor name: ", QLineEdit::Normal, QString(), &ok);
        if(name == "" || !ok) {
            return;
        } else if(!ui->actorsListWidget->findItems(name, Qt::MatchFlag::MatchExactly).size()) {
            ui->actorsListWidget->addItem(name);
            ui->actorsComboBox->addItem(name);
            return;
        }

        actorExists = true;
    }
}

void MainWindow::removeActor()
{
    for(auto actors: ui->actorsListWidget->selectedItems()) {
        ui->actorsListWidget->takeItem(ui->actorsListWidget->row(actors));
        ui->actorsComboBox->removeItem(ui->actorsComboBox->findText(actors->text()));
    }
}

void MainWindow::setHost()
{
    QString host = QInputDialog::getText(this, "Host", "Host name: ", QLineEdit::Normal, HttpWorker::getHost());
    if(!host.isEmpty()) {
        HttpWorker::setHost(host);
    }
}

void MainWindow::setPort()
{
    int port = QInputDialog::getInt(this, "Port", "Port: ", HttpWorker::getPort(), QLineEdit::Normal);
    if(port) {
        HttpWorker::setPort(port);
    }
}

void MainWindow::setJsonToWidgets(QJsonDocument jsonDocument)
{
    ui->titleTextEdit->clear();
    ui->actorsListWidget->clear();
    ui->actorsComboBox->clear();

    ui->titleTextEdit->setText(jsonDocument["title"].toString());
    QJsonArray actors = jsonDocument["actors"].toArray();

    for(auto actor: actors) {
        ui->actorsListWidget->addItem(actor.toString());
        ui->actorsComboBox->addItem(actor.toString());
    }

    ui->actorsListWidget->addItem(jsonDocument["systemActor"].toString());
    ui->actorsComboBox->addItem(jsonDocument["systemActor"].toString());
    ui->actorsComboBox->setCurrentText(jsonDocument["systemActor"].toString());

    ui->textEdit->setText(QJsonDocument(jsonDocument["steps"].toArray()).toJson());
}

QJsonDocument MainWindow::createJsonFromWidgets()
{
    QJsonObject root;
    root["title"] = ui->titleTextEdit->toPlainText();

    QJsonArray actors;
    for(int i = 0; i<ui->actorsListWidget->count(); i++) {
        QString actor = ui->actorsListWidget->item(i)->text();

        if(actor != ui->actorsComboBox->currentText()) {
            actors.append(ui->actorsListWidget->item(i)->text());
        }
    }

    root["actors"] = actors;
    root["systemActor"] = ui->actorsComboBox->currentText();
    root["steps"] = QJsonDocument::fromJson(ui->textEdit->toPlainText().toLatin1()).array();

    return QJsonDocument(root);
}

QPair<QJsonDocument, bool> MainWindow::addDepthLevel(QJsonDocument)
{
    bool ok;
    int depth;


    depth = QInputDialog::getInt(this, "Depth", "Depth level: ", 1, 0, 2147483647, 1, &ok);
    if(!ok) {
        return QPair<QJsonDocument, bool>(QJsonDocument(), false);
    }

    QJsonDocument doc = createJsonFromWidgets();
    QJsonObject root;
    root["cutDepthLevel"] = depth;
    root["scenario"] = doc.object();

    return QPair<QJsonDocument, bool>(QJsonDocument(root), true);
}
