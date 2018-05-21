#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = 0);
    ~Application();

    bool saveFile();
    bool createFile();

protected:
    void paintEvent(QPaintEvent *event);                    // 重写 paintEvent 事件

    void drawNavWidgets(short select = 0);                    // 绘制导航栏部件
    void drawFileEditPage(short mode = 0);                    // 绘制文件信息页面
    void drawDiscernPage();                                   // 绘制音符识别页面
    void drawPlayerPage();                                    // 绘制播放页面
    void drawListPage();                                      // 绘制播放列表页面

private:
    Ui::Application *ui;


};

#endif // FORM_H
