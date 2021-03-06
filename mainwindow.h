#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

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
    void ChangeLanguage(int index);

protected:
    void changeEvent(QEvent *event);

private slots:
    void on_actionAboutMenu_triggered();

    void on_actionGithub_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator *m_translator;

};
#endif // MAINWINDOW_H
