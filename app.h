#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QCloseEvent>
#include <QString>
#include <QGraphicsView>
#include <QSlider>
#include <QPushButton>
#include "lib/player/player.h"
#include "lib/midifile/midifile.h"

namespace Ui {
class App;
}

/* App 应用程序类 */
class App : public QWidget
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

protected:
    Player          player;                                                     // 播放器
    MidiFile        edMidiFile;                                                 // 正在编辑的 MIDI 文件

    void            connectSlots                ();                             // 关联信号与槽

    void            paintEvent                  (QPaintEvent *e);               // 重写 paintEvent 事件
    void            closeEvent                  (QCloseEvent *e);               // 重写 closeEvent 事件

    void            allPages_hide               ();                             // 隐藏所有页面组件

    void            initCamera                  ();                             // 初始化摄像头设备
    void            showCameraImg               ();                             // 显示摄像头拍摄的图像
    void            captureImg                  ();                             // 捕获图像
    void            closeCamera                 ();                             // 关闭摄像头显示

    void            loadTrack                   (MidiTrack track);              // 在编辑区中加载音轨序列

    void            newMidiFile                 ();                             // 新建 MIDI 文件
    void            saveMidiFile                ();                             // 保存 MIDI 文件
    void            closeMidiFile               ();                             // 关闭 MIDI 文件

private:
    Ui::App *ui;

    const QString   PLAY_STATUS_STYLE =
            "image:url(:/playPage/resource/playPage/playSong.svg)";             // 播放状态图标
    const QString   PAUSE_STATUS_STYLE =
            "image:url(:/playPage/resource/playPage/pauseSong.svg)";            // 暂停状态图标


/* 信号槽 */
private slots:
    void            lineEdit_textChanged        ();                             // 单行输入框::文本内容被改变
    void            slider_valueChanged         (int value);                    // 滑动条::值被改变
    void            navBtn_clicked              ();                             // 导航栏按钮::被单击
    void            playerBtn_clicked           ();                             // 播放器按钮::被单击
    void            playerConsoleBtn_clicked    ();                             // 播放控制台按钮::被单击
    void            playListBtn_clicked         ();                             // 播放列表按钮::被单击
    void            playList_doubleClicked      (const QModelIndex &index);     // 播放列表::被双击
    void            settingBtn_clicked          ();                             // 设置中心的按钮::被单击
    void            settingCheckBox_stateChanged();                             // 设置中心的复选框::状态被改变
    void            settingSpinBox_valueChanged (int arg1);                     // 设置中心的调节框::值被改变
    void            tracksConsoleBtn_clicked    ();                             // 音轨控制台按钮::被单击
    void            toolBarsBtn_clicked         ();                             // 工具栏按钮::被单击
    void            editFileBtn_clicked         ();                             // 编辑区文件按钮::被单击
    void            editMidiBtn_clicked         ();                             // 编辑区 MIDI 控制按钮::被单击
    void            editMidiSpinBox_valueChanged(int arg1);                     // 编辑区 MIDI 控制调节框::值被改变
};

#endif // APP_H
