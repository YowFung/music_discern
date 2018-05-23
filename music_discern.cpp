#include "music_discern.h"
#include "ui_music_discern.h"

// 构造方法
Application::Application(QWidget *parent) : QWidget(parent), ui(new Ui::Application)
{
    ui->setupUi(this);

    // 初始化窗体部件
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);             // 窗口无边框|总在最前
    ui->app_slogan->setAttribute(Qt::WA_TransparentForMouseEvents,true);            // 鼠标穿透 slogan

    // 默认显示首页
    showHome();

    // 关联信号与槽
    connect(ui->nav_home, &QPushButton::clicked, this, &Application::showHome);
    connect(ui->set_edit_instruments_down, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->set_edit_instruments_up, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->set_play_instruments_down, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->set_play_instruments_up, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->btn_instruments_down, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->btn_instruments_up, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->con_instruments_down, &QPushButton::clicked, this, &Application::change_instrument);
    connect(ui->con_instruments_up, &QPushButton::clicked, this, &Application::change_instrument);
}

// 析构方法
Application::~Application()
{
    delete preview_instrument;
    delete play_instrument;
    delete def_preview_instrument;
    delete def_play_instrument;
    delete ui;
}

// 关闭窗口事件
void Application::closeEvent(QCloseEvent *)
{

}

// 窗口重绘事件
void Application::paintEvent(QPaintEvent *)
{
    // 设置窗口背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/app/resource/app/bg.jpg"));
}

// 显示首页
void Application::showHome()
{
    // 隐藏标题和所有页面
    ui->app_title->setVisible(false);
    ui->editBox->setVisible(false);
    ui->playBox->setVisible(false);
    ui->settingBox->setVisible(false);
    ui->helpBox->setVisible(false);

    // 取消所有导航栏按钮的选中状态
    QObjectList btn_objs = ui->nav->children();
    foreach (QObject *btn_obj, btn_objs) {
        QPushButton *btn = qobject_cast<QPushButton*>(btn_obj);
        btn->setChecked(false);
    }
}

// 显示「MIDI 编辑区」页面
void Application::on_nav_edit_clicked()
{
    showHome();
    ui->app_title->setText("MIDI 编辑区");
    ui->app_title->setVisible(true);
    ui->editBox->setVisible(true);
    ui->nav_edit->setChecked(true);
}

// 显示「MIDI 演播室」页面
void Application::on_nav_play_clicked()
{
    showHome();
    ui->app_title->setText("MIDI 演播室");
    ui->app_title->setVisible(true);
    ui->playBox->setVisible(true);
    ui->nav_play->setChecked(true);
}

// 显示「设置 & 关于」页面
void Application::on_nav_setting_clicked()
{
    showHome();
    ui->app_title->setText("设置 & 关于");
    ui->app_title->setVisible(true);
    ui->settingBox->setVisible(true);
    ui->nav_setting->setChecked(true);
}

// 显示「帮助中心」页面
void Application::on_nav_help_clicked()
{
    showHome();
    ui->app_title->setText("帮助中心");
    ui->app_title->setVisible(true);
    ui->helpBox->setVisible(true);
    ui->nav_help->setChecked(true);
}

// 切换乐器
void Application::change_instrument()
{
    Instrument *target_instrument = nullptr;
    QPushButton *target_name_btn = nullptr;
    short operate_type = 0;
    QPushButton *obj = qobject_cast<QPushButton *>(sender());

    // 获取目标对象::编辑区默认乐器
    if (obj->objectName() == "set_edit_instruments_down") {
        target_instrument = def_preview_instrument;
        target_name_btn = ui->set_edit_instruments_name;
        operate_type = -1;
    }
    if (obj->objectName() == "set_edit_instruments_up") {
        target_instrument = def_preview_instrument;
        target_name_btn = ui->set_edit_instruments_name;
        operate_type = 1;
    }
    // 获取目标对象::演播室默认乐器
    if (obj->objectName() == "set_play_instruments_down") {
        target_instrument = def_play_instrument;
        target_name_btn = ui->set_play_instruments_name;
        operate_type = -1;
    }
    if (obj->objectName() == "set_play_instruments_up") {
        target_instrument = def_play_instrument;
        target_name_btn = ui->set_play_instruments_name;
        operate_type = 1;
    }
    // 获取目标对象::编辑区乐器
    if (obj->objectName() == "btn_instruments_down") {
        target_instrument = preview_instrument;
        target_name_btn = ui->btn_instruments_name;
        operate_type = -1;
    }
    if (obj->objectName() == "btn_instruments_up") {
        target_instrument = preview_instrument;
        target_name_btn = ui->btn_instruments_name;
        operate_type = 1;
    }
    // 获取目标对象::演播室乐器
    if (obj->objectName() == "con_instruments_down") {
        target_instrument = play_instrument;
        target_name_btn = ui->con_instruments_name;
        operate_type = -1;
    }
    if (obj->objectName() == "con_instruments_up") {
        target_instrument = play_instrument;
        target_name_btn = ui->con_instruments_name;
        operate_type = 1;
    }

    // 针对目标进行切换乐器
    if (target_instrument != nullptr)
        target_instrument->switchoverInstrument(operate_type, target_name_btn);
}
