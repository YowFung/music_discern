#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent) : QWidget(parent), ui(new Ui::App)
{
    ui->setupUi(this);

    // 初始化窗体部件
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);             // 窗口无边框|总在最前
    ui->app_slogan->setAttribute(Qt::WA_TransparentForMouseEvents,true);            // 鼠标穿透 slogan

    // 默认隐藏所有页面
    allPages_hide();

    // 关联信号与槽
    connectSlots();


}

App::~App()
{
    delete ui;
}

// 关联信号与槽
void App::connectSlots()
{
    connect(ui->nav_home, &QPushButton::clicked, this, &App::allPages_hide);                            // 导航栏按钮: 首页
    connect(ui->nav_edit, &QPushButton::clicked, this, &App::navBtn_clicked);                           // 导航栏按钮: 编辑区
    connect(ui->nav_play, &QPushButton::clicked, this, &App::navBtn_clicked);                           // 导航栏按钮: 演播室
    connect(ui->nav_setting, &QPushButton::clicked, this, &App::navBtn_clicked);                        // 导航栏按钮: 设置中心
    connect(ui->nav_help, &QPushButton::clicked, this, &App::navBtn_clicked);                           // 导航栏按钮: 帮助中心
    connect(ui->nav_exit, &QPushButton::clicked, this, &App::close);                                    // 导航栏按钮: 退出

    connect(ui->player_play, &QPushButton::clicked, this, &App::playerBtn_clicked);                     // 播放器按钮: 播放暂停
    connect(ui->player_stop, &QPushButton::clicked, this, &App::playerBtn_clicked);                     // 播放器按钮: 停止
    connect(ui->player_last, &QPushButton::clicked, this, &App::playerBtn_clicked);                     // 播放器按钮: 上一曲
    connect(ui->player_next, &QPushButton::clicked, this, &App::playerBtn_clicked);                     // 播放器按钮: 下一曲

    connect(ui->playList, &QListWidget::doubleClicked, this, &App::playList_doubleClicked);             // 播放列表: 双击

    connect(ui->song_play, &QPushButton::clicked, this, &App::playListBtn_clicked);                     // 播放列表按钮: 播放
    connect(ui->song_add, &QPushButton::clicked, this, &App::playListBtn_clicked);                      // 播放列表按钮: 添加
    connect(ui->song_remove, &QPushButton::clicked, this, &App::playListBtn_clicked);                   // 播放列表按钮: 移除
    connect(ui->song_edit, &QPushButton::clicked, this, &App::playListBtn_clicked);                     // 播放列表按钮: 编辑
    connect(ui->song_info, &QPushButton::clicked, this, &App::playListBtn_clicked);                     // 播放列表按钮: 查看信息

    connect(ui->con_velocity, &QSlider::valueChanged, this, &App::slider_valueChanged);                 // 播放控制台滑块: 速度调节
    connect(ui->con_tone, &QSlider::valueChanged, this, &App::slider_valueChanged);                     // 播放控制台滑块: 变调调节
    connect(ui->con_volume, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 总音量调节
    connect(ui->con_track1, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨1音量调节
    connect(ui->con_track2, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨2音量调节
    connect(ui->con_track3, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨3音量调节
    connect(ui->con_track4, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨4音量调节
    connect(ui->con_track5, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨5音量调节
    connect(ui->con_track6, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨6音量调节
    connect(ui->con_track7, &QSlider::valueChanged, this, &App::slider_valueChanged);                   // 播放控制台滑块: 音轨7音量调节

    connect(ui->con_instruments_down, &QPushButton::clicked, this, &App::playerConsoleBtn_clicked);     // 播放控制台按钮: 向下切换乐器
    connect(ui->con_instruments_up, &QPushButton::clicked, this, &App::playerConsoleBtn_clicked);       // 播放控制台按钮: 向上切换乐器

    connect(ui->set_instruments_down, &QPushButton::clicked, this, &App::settingBtn_clicked);           // 设置中心按钮: 向下切换乐器
    connect(ui->set_instruments_up, &QPushButton::clicked, this, &App::settingBtn_clicked);             // 设置中心按钮: 向上切换乐器

    connect(ui->set_tone, SIGNAL(valueChanged(int)), this, SLOT(settingSpinBox_valueChanged));          // 设置中心调节框: 变调调节
    connect(ui->set_velocity, SIGNAL(valueChanged(int)), this, SLOT(settingSpinBox_valueChanged));      // 设置中心调节框: 速度调节

    connect(ui->set_autoNext, &QCheckBox::stateChanged, this, &App::settingCheckBox_stateChanged);      // 设置中心复选框: 自动下一曲
    connect(ui->set_loop, &QCheckBox::stateChanged, this, &App::settingCheckBox_stateChanged);          // 设置中心复选框: 列表循环

    connect(ui->input_songName, &QLineEdit::textChanged, this, &App::lineEdit_textChanged);             // 编辑区文本输入框: 歌曲名

    connect(ui->btn_instruments_down, &QPushButton::clicked, this, &App::editMidiBtn_clicked);          // 编辑区 MIDI 控制按钮: 向下切换乐器
    connect(ui->btn_instruments_up, &QPushButton::clicked, this, &App::editMidiBtn_clicked);            // 编辑区 MIDI 控制按钮: 向上切换乐器

    connect(ui->spin_tone, SIGNAL(valueChanged(int)), this, SLOT(editMidiSpinBox_valueChanged));        // 编辑区 MIDI 控制调节器: 变调调节
    connect(ui->spin_velocity, SIGNAL(valueChanged(int)), this, SLOT(editMidiSpinBox_valueChanged));    // 编辑区 MIDI 控制调节器: 速度调节

    connect(ui->btn_playTracks, &QPushButton::clicked, this, &App::tracksConsoleBtn_clicked);           // 编辑区音轨控制按钮: 播放歌曲
    connect(ui->btn_previewTrack, &QPushButton::clicked, this, &App::tracksConsoleBtn_clicked);         // 编辑区音轨控制按钮: 预览音轨序列
    connect(ui->btn_removeTrack, &QPushButton::clicked, this, &App::tracksConsoleBtn_clicked);          // 编辑区音轨控制按钮: 移除音轨

    connect(ui->toolbar_firstStep, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);             // 编辑区工具栏按钮: 跳到开头
    connect(ui->toolbar_lastStep, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);              // 编辑区工具栏按钮: 上一个音符
    connect(ui->toolbar_nextStep, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);              // 编辑区工具栏按钮: 下一个音符
    connect(ui->toolbar_endStep, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);               // 编辑区工具栏按钮: 跳到结尾
    connect(ui->toolbar_play, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);                  // 编辑区工具栏按钮: 播放音轨
    connect(ui->toolbar_preview, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);               // 编辑区工具栏按钮: 播放音符
    connect(ui->toolbar_insert, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);                // 编辑区工具栏按钮: 插入音符
    connect(ui->toolbar_delete, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);                // 编辑区工具栏按钮: 删除音符
    connect(ui->toolbar_pitchDown, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);             // 编辑区工具栏按钮: 降调
    connect(ui->toolbar_pitchUp, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);               // 编辑区工具栏按钮: 升调
    connect(ui->toolbar_octaveDown, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);            // 编辑区工具栏按钮: 降低八度
    connect(ui->toolbar_octaveUp, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);              // 编辑区工具栏按钮: 升高八度
    connect(ui->toolbar_durationDown, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);          // 编辑区工具栏按钮: 减短时值
    connect(ui->toolbar_durationUp, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);            // 编辑区工具栏按钮: 延长时值
    connect(ui->toolbar_quit, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);                  // 编辑区工具栏按钮: 放弃编辑
    connect(ui->toolbar_add, &QPushButton::clicked, this, &App::toolBarsBtn_clicked);                   // 编辑区工具栏按钮: 添加到文件

    connect(ui->btn_newFile, &QPushButton::clicked, this, &App::editFileBtn_clicked);                   // 编辑区文件操作按钮: 新建 MIDI 文件
    connect(ui->btn_closeFile, &QPushButton::clicked, this, &App::editFileBtn_clicked);                 // 编辑区文件操作按钮: 关闭 MIDI 文件
    connect(ui->btn_capture, &QPushButton::clicked, this, &App::editFileBtn_clicked);                   // 编辑区文件操作按钮: 获取摄像头图像
}

// 重写 closeEvent 事件
void App::closeEvent(QCloseEvent *)
{

}

// 重写 paintEvent 事件
void App::paintEvent(QPaintEvent *)
{
    // 设置窗口背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/app/resource/app/bg.jpg"));
}

// 隐藏所有页面组件
void App::allPages_hide()
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

// 初始化摄像头设备
void App::initCamera()
{

}

// 显示摄像头拍摄的图像
void App::showCameraImg()
{

}

// 捕获图像
void App::captureImg()
{

}

// 关闭摄像头显示
void App::closeCamera()
{

}

// 在编辑区中加载音轨序列
void App::loadTrack(MidiTrack track)
{

}

// 新建 MIDI 文件
void App::newMidiFile()
{

}

// 保存 MIDI 文件
void App::saveMidiFile()
{

}

// 关闭 MIDI 文件
void App::closeMidiFile()
{

}


// 单行输入框::文本内容被改变
void App::lineEdit_textChanged()
{
    QLineEdit *obj = qobject_cast<QLineEdit *>(sender());
    int obj_id = 0;
    obj->objectName() == "input_songName" && (obj_id = 1);      // 编辑区的歌曲名编辑框

    switch (obj_id) {
    case 1: edMidiFile.setSongTitle(obj->text()); break;
    }
}

// 滑动条::值被改变
void App::slider_valueChanged(int value)
{
    QSlider *obj = qobject_cast<QSlider *>(sender());
    int obj_id = 0;
    obj->objectName() == "con_velocity" && (obj_id = 1);        // 演播室控制台的速度调节滑块
    obj->objectName() == "con_tone" && (obj_id = 2);            // 演播室控制台的变调调节滑块
    obj->objectName() == "con_volume" && (obj_id = 3);          // 演播室控制台的总音量调节滑块
    obj->objectName().startsWith("con_track") && (obj_id = 4);  // 演播室控制台的各音轨音量调节滑块

    switch (obj_id) {
    case 1: {
        if (player.setVelocity((char)value))
            ui->con_label_velocity->setText(QString::number(value));
    }; break;
    case 2: {
        if (player.setTone((char)value))
            ui->con_label_tone->setText(QString::number(value));
    }; break;
    case 3: {
        if (player.setVolume(0, (char)value))
            ui->con_label_volume->setText(QString::number(value));
    }; break;
    case 4: {

    }; break;
    }
}

// 导航栏按钮::被单击
void App::navBtn_clicked()
{
    QPushButton *obj = qobject_cast<QPushButton *>(sender());
    int obj_id = 0;
    obj->objectName() == "nav_edit" && (obj_id = 1);            // 编辑区
    obj->objectName() == "nav_play" && (obj_id = 2);            // 演播室
    obj->objectName() == "nav_setting" && (obj_id = 3);         // 设置中心
    obj->objectName() == "nav_help" && (obj_id = 4);            // 帮助中心

    allPages_hide();

    switch (obj_id) {
    case 1: {
        ui->app_title->setText("MIDI 编辑区");
        ui->app_title->setVisible(true);
        ui->editBox->setVisible(true);
        ui->nav_edit->setChecked(true);
    }; break;
    case 2: {
        ui->app_title->setText("MIDI 演播室");
        ui->app_title->setVisible(true);
        ui->playBox->setVisible(true);
        ui->nav_play->setChecked(true);
    }; break;
    case 3: {
        ui->app_title->setText("设置 & 关于");
        ui->app_title->setVisible(true);
        ui->settingBox->setVisible(true);
        ui->nav_setting->setChecked(true);
    }; break;
    case 4: {
        ui->app_title->setText("帮助中心");
        ui->app_title->setVisible(true);
        ui->helpBox->setVisible(true);
        ui->nav_help->setChecked(true);
    }; break;
    }

}

// 播放器按钮::被单击
void App::playerBtn_clicked()
{
    QPushButton *obj = qobject_cast<QPushButton *>(sender());
    int obj_id = 0;
    obj->objectName() == "player_play" && (obj_id = 1);         // 播放/暂停按钮
    obj->objectName() == "player_stop" && (obj_id = 2);         // 停止按钮
    obj->objectName() == "player_last" && (obj_id = 3);         // 上一曲按钮
    obj->objectName() == "player_next" && (obj_id = 4);         // 下一曲按钮

    ui->player_play->setStyleSheet(PLAY_STATUS_STYLE);          // 修改播放按钮样式

    switch (obj_id) {
    case 1: {
        if ((player.status() == 0 || player.status() == 3) && player.list.currentRow() >= 0) {
            if (player.load(player.list.currentRow()))          // 加载文件并播放
                player.play();
        }
        else if (player.status() == 1)
            player.pause();                                     // 暂停播放
        else if (player.status() == 2)
            player.play();                                      // 继续播放
    }; break;
    case 2: player.stop(); break;
    case 3: player.lastSong(); break;
    case 4: player.nextSong(); break;
    }

    // 修改播放按钮样式
    if (player.status() == 1)
        ui->player_play->setStyleSheet(PAUSE_STATUS_STYLE);
}

// 播放控制台按钮::被单击
void App::playerConsoleBtn_clicked()
{
    QPushButton *obj = qobject_cast<QPushButton *>(sender());
    int obj_id = 0;
    obj->objectName() == "con_instruments_down" && (obj_id = 1);// 切换为上一个乐器
    obj->objectName() == "con_instruments_up" && (obj_id = 2);  // 切换为下一个乐器

    switch (obj_id) {
    case 1: {
        QString name = player.instrument.turnInstrument(Instrument::TURN_DOWN);
        if (name != "")
            ui->con_instruments_name->setText(name);
    }; break;
    case 2: {
        QString name = player.instrument.turnInstrument(Instrument::TURN_UP);
        if (name != "")
            ui->con_instruments_name->setText(name);
    }; break;
    }
}

// 播放列表按钮::被单击
void App::playListBtn_clicked()
{
    QPushButton *obj = qobject_cast<QPushButton *>(sender());
    int obj_id = 0;
    obj->objectName() == "song_play" && (obj_id = 1);           // 播放
    obj->objectName() == "song_add" && (obj_id = 2);            // 添加
    obj->objectName() == "song_remove" && (obj_id = 3);         // 移除
    obj->objectName() == "song_edit" && (obj_id = 4);           // 编辑
    obj->objectName() == "song_info" && (obj_id = 5);           // 查看信息

    switch (obj_id) {
    case 1: {
        if (ui->playList->currentRow() >= 0)
            playList_doubleClicked(ui->playList->currentIndex());
    }; break;
    case 2: {

    }; break;
    case 3: {
        int index = ui->playList->currentRow();
        if (index = player.list.currentRow()) {
            ui->player_play->setStyleSheet(PLAY_STATUS_STYLE);
            player.stop();
            if (player.list.remove(index))
                ui->playList->removeItemWidget(ui->playList->currentItem());
        }
    }; break;
    case 4: {
        // 暂停演播
        ui->player_play->setStyleSheet(PLAY_STATUS_STYLE);
        if (player.status() == 1)
            player.pause();

        // 跳到编辑区页面
        ;

        // 编辑区打开当前选中的文件
        ;
    }; break;
    }
}

// 播放列表::被双击
void App::playList_doubleClicked(const QModelIndex &index)
{
    // 停止正在播放的音乐
    ui->player_play->setStyleSheet(PLAY_STATUS_STYLE);
    player.stop();

    // 播放选中的音乐
    if ( ui->playList->currentRow() >= 0
            && player.list.selected(index.row())
            && player.load(player.list.currentRow()) ) {
        player.play();
    }

    // 修改播放按钮样式
    if (player.status() == 1)
        ui->player_play->setStyleSheet(PAUSE_STATUS_STYLE);
}

// 设置中心的按钮::被单击
void App::settingBtn_clicked()
{

}

// 设置中心的复选框::状态被改变
void App::settingCheckBox_stateChanged()
{

}

// 设置中心的调节框::值被改变
void App::settingSpinBox_valueChanged(int arg1)
{

}

// 音轨控制台按钮::被单击
void App::tracksConsoleBtn_clicked()
{

}

// 工具栏按钮::被单击
void App::toolBarsBtn_clicked()
{

}

// 编辑区文件按钮::被单击
void App::editFileBtn_clicked()
{

}

// 编辑区 MIDI 控制按钮::被单击
void App::editMidiBtn_clicked()
{

}

// 编辑区 MIDI 控制调节框::值被改变
void App::editMidiSpinBox_valueChanged(int arg1)
{

}
