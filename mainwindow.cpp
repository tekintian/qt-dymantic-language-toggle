#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include "aboutdialog.h"

#include <QDebug>
#define cout qDebug()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),m_translator(new QTranslator)
{
    ui->setupUi(this);


    //监听语言下拉框改变事件
    connect(ui->language_box, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        ChangeLanguage(index);
    });

 ChangeLanguage(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ChangeLanguage(int index)
{
    QString exePath = QApplication::applicationDirPath();
    QString QmName;

    if(index == 1)
    {
        QmName = ":/demo_zh_CN.qm";
    }
    else
    {
        QmName =":/demo_en.qm";
    }

    cout<<index;
    cout<< QmName << exePath ;

    if( m_translator->load(QmName) )
    {
        // 每次只需 installTranslator 系统会自动发送一个QEvent::LanguageChange信号 通过重写eventChange事件可捕获
        //QEvent::LanguageChange  89  The application translation changed.
        qApp ->installTranslator(m_translator);

        cout<<"install OK";

        //这个非常关键, 重新翻译UI
//       ui->retranslateUi(this);

    }else{
        cout<<"load fail";
    }
}

/**
 * [virtual protected] void QWidget::changeEvent(QEvent *event)
 * @brief MainWindow::changeEvent 重写事件,捕获自己想要处理的事件进行处理
 * @param event
 */
void MainWindow::changeEvent(QEvent *event)
{
    //enum QEvent::Type
    // event->type(); 返回的是事件类型枚举  也就是int类型 QT中的枚举值都是int类型
    int type = event->type();
    switch (type) {
    case QEvent::LanguageChange:
        cout<<"捕获到语言改变事件";
        //重新翻译UI
        ui->retranslateUi(this);
        break;
    }

    //其他的事件交由 QWidget 去处理
    QWidget::changeEvent(event);

}
// 打开About窗口
void MainWindow::on_actionAboutMenu_triggered()
{
    AboutDialog *adialog = new AboutDialog(this);
    adialog->exec();

}
//打开连接
void MainWindow::on_actionGithub_triggered()
{
    AboutDialog::openUrl("https://github.com/tekintian/");
}
