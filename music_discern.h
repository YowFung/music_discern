#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QPaintEvent>
#include <QCloseEvent>

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

    void hideAllPages();                                // 隐藏所有页面

private slots:
    void on_nav_home_clicked();
    void on_nav_edit_clicked();
    void on_nav_play_clicked();
    void on_nav_setting_clicked();
    void on_nav_help_clicked();

    void changeCursorToDefault();                       // 设置鼠标指针为默认指针
};

#endif // FORM_H
