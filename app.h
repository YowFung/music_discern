#ifndef APP_H
#define APP_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QCloseEvent>
#include <QString>
#include <QChar>
#include <QGraphicsView>
#include <QSlider>
#include <QPushButton>
#include "instrument.h"

namespace Ui {
class App;
}

class App : public QWidget
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

protected:
    void paintEvent(QPaintEvent *e);                    // 重写 paintEvent 事件
    void closeEvent(QCloseEvent *e);                    // 重写 closeEvent 事件

private:
    Ui::App *ui;

    // 创建乐器对象实例
    Instrument *preview_instrument = new Instrument();      // 在编辑页面
    Instrument *play_instrument = new Instrument();         // 在播放页面
    Instrument *def_preview_instrument = new Instrument();  // 在编辑页面（默认）
    Instrument *def_play_instrument = new Instrument();     // 在播放页面（默认）

private slots:
    void showHome();                                    // 显示首页
    void on_nav_edit_clicked();                         // 导航栏->编辑::被点击
    void on_nav_play_clicked();                         // 导航栏->演播::被点击
    void on_nav_setting_clicked();                      // 导航栏->设置::被点击
    void on_nav_help_clicked();                         // 导航栏->帮助::被点击
    void change_instrument();                           // 切换乐器
};

#endif // APP_H
