#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void httpRequestCountSteps();
    void httpRequestCountKeywords();
    void httpRequestFindLinesNotStartingWithAnActor();
    void httpRequestCutToDepth();
    void httpRequestGenerateNumberedList();
    void loadJSON();
    void addActor();
    void removeActor();
    void setHost();
    void setPort();

private:
    const QString appName = "Scenario Quality Checker";
    Ui::MainWindow *ui;

    void setJsonToWidgets(QJsonDocument jsonDocument);
    QJsonDocument createJsonFromWidgets();
    QPair<QJsonDocument, bool> addDepthLevel(QJsonDocument);
};
#endif // MAINWINDOW_H
