#include "aboutdialog.h"
#include "ui_aboutdialog.h"

//打开URL连接库
#include <QUrl>
#include <QDesktopServices>

#include <QDebug>
#define cout qDebug()

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    //打开label中的连接
    void (QLabel::*sigLa)(const QString &link) = &QLabel::linkActivated;
    connect(ui->about_desc,sigLa,[=](const QString &link){
        cout<<"link actived"<< link;
        openUrl(link);
    });

}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    accept();
}

void AboutDialog::openUrl(QString url)
{
     QDesktopServices::openUrl(QUrl(url));
}
