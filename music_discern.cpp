#include "music_discern.h"
#include "ui_music_discern.h"

#include <QString>
#include <QPainter>
#include <QGraphicsView>
#include <QSlider>
#include <QCursor>

// 构造方法
Application::Application(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);

    // 初始化窗体部件
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint | Qt::WindowStaysOnTopHint);
    ui->app_slogan->setAttribute(Qt::WA_TransparentForMouseEvents,true);                                // 鼠标穿透

    // 启动时隐藏所有页面
    hideAllPages();

}

// 析构方法
Application::~Application()
{
    delete ui;
}

// 关闭窗口事件
void Application::closeEvent(QCloseEvent *)
{

}

// 绘制窗口事件
void Application::paintEvent(QPaintEvent *)
{
    // 设置窗口背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/app/resource/app/bg.jpg"));
}

// 修改鼠标指针为默认指针
void Application::changeCursorToDefault()
{
    QSlider *obj = qobject_cast<QSlider *>(sender());
    obj->setCursor(Qt::ArrowCursor);
}

// 隐藏所有页面
void Application::hideAllPages()
{
    ui->app_title->setVisible(false);
    ui->editBox->setVisible(false);
    ui->playBox->setVisible(false);
    ui->settingBox->setVisible(false);
    ui->helpBox->setVisible(false);
}

// 显示首页
void Application::on_nav_home_clicked()
{
    hideAllPages();
}

// 显示「MIDI 编辑区」页面
void Application::on_nav_edit_clicked()
{
    hideAllPages();
    ui->app_title->setText("MIDI 编辑区");
    ui->app_title->setVisible(true);
    ui->editBox->setVisible(true);
}

// 显示「MIDI 演播室」页面
void Application::on_nav_play_clicked()
{
    hideAllPages();
    ui->app_title->setText("MIDI 演播室");
    ui->app_title->setVisible(true);
    ui->playBox->setVisible(true);
}

// 显示「设置 & 关于」页面
void Application::on_nav_setting_clicked()
{
    hideAllPages();
    ui->app_title->setText("设置 & 关于");
    ui->app_title->setVisible(true);
    ui->settingBox->setVisible(true);
}

// 显示「帮助中心」页面
void Application::on_nav_help_clicked()
{
    hideAllPages();
    ui->app_title->setText("帮助中心");
    ui->app_title->setVisible(true);
    ui->helpBox->setVisible(true);
}
