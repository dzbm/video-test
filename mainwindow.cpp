#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>

//extern "C"
//{
//    #include <libavdevice/avdevice.h>
//}



 QMediaPlayer *player = new QMediaPlayer();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    avcodec_configuration();
    unsigned version = avcodec_version();
    QString ch = QString::number(version,10);
    qDebug()<<"version: "<<version;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_set_clicked()
{
   // player->setMedia(QMediaContent(QUrl::fromLocalFile("D:/zy/dyht.mp3")));
     player->setMedia(QMediaContent(QUrl::fromLocalFile("D:/zy/dyht.mp4")));//路径由本机决定


     player->setVideoOutput(ui->widget_video);//widget控件名称


}

void MainWindow::on_pushButton_start_clicked()
{
 player->play();
}

