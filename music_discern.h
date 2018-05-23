#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QCloseEvent>
#include <QString>
#include <QChar>
#include <QGraphicsView>
#include <QSlider>
#include <QCursor>
#include <QPushButton>
#include "instrument.h"

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = 0);
    ~Application();

protected:
    void paintEvent(QPaintEvent *e);                    // 重写 paintEvent 事件
    void closeEvent(QCloseEvent *e);                    // 重写 closeEvent 事件

private:
    Ui::Application *ui;

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

#endif // FORM_H
