#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>
#include <QStringList>
#include <QPushButton>

class Instrument
{
public:
    Instrument();

    QString getInstrumentName(short instrument_id);                         // 通过乐器 ID 获取乐器名称
    short getInstrumentId(QString instrument_name);                         // 通过乐器名称获取乐器 ID
    void setInstrument(short instrument_id);                                // 设定为特定乐器
    void switchoverInstrument(short operate_type, QPushButton *show_btn);   // 切换为上一个或下一个乐器(显示在 QPushButton 组件上)

    QString currentInstrumentName = "声学大钢琴";                            // 当前乐器名称
    short currentInstrumentId = 0;                                          // 当前乐器 ID

private:
    // 定义乐器的名称表
    QStringList instruments = {
        "声学大钢琴",
        "明亮的钢琴",
        "电钢琴",
        "酒吧钢琴",
        "柔和的电钢琴",
        "加合唱效果的电钢琴",
        "羽管键琴（拨弦古钢琴）",
        "科拉维科特琴（击弦古钢琴）",
        "钢片琴"
    };

};

#endif // INSTRUMENT_H
