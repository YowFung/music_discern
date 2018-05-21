#include "music_discern.h"
#include "ui_music_discern.h"

#include <QString>
#include <QPainter>

Application::Application(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);

    // 设置窗口为无边框、置顶显示
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint | Qt::WindowStaysOnTopHint);

    int currentPage = 0;                                       // 当前所在的页面：0=首页, 1=文件编辑, 2=乐谱创作, 3=乐谱预览, 4=音乐演播, 5=文件列表, 6=关于我们
    int currentMode = 0;                                       // 当前的程序模式：0=待机, 1=识别, 2=播放

    QString playingFilename = "";                               // 播放中的文件名
    short playerStatus = 0;                                    // 播放器状态: 0=未知, 1=正在播放, 2=正在暂停, 3=停止待机

    QString editingFilename = "untitled.mid";                   // 编辑中的文件名
    bool fileIsSave = true;                                   // 正在编辑的文件是否已保存
}

Application::~Application()
{
    delete ui;
}

void Application::paintEvent(QPaintEvent *)
{
    // 设置窗口背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/images/bg.jpg"));
}
