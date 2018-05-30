#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>
#include <QMap>

typedef QMap<char, QString>::iterator    KeyVal;
typedef QMap<char, QString>              maps;

/* 乐器类 */
class Instrument
{
public:
    Instrument();

    static const char  TURN_DOWN       = -1;            // 调节类型为向下调节
    static const char  TURN_UP         = 1;             // 调节类型为向上调节

    QString     getName         (char id);              // 通过乐器 ID 获取乐器名称 (空字符串则表示该乐器不存在)
    char         getId          (QString name);         // 通过乐器名称获取乐器 ID (-1则表示该乐器不存在)
    int         count           ();                     // 获取乐器总数
    bool        isExisting      (char id);              // 乐器 id 是否存在
    bool        isExisting      (QString name);         // 乐器名称是否存在
    QString     turnInstrument  (char turn_type);       // 切换乐器 (TURN_UP | TURN_DOWN)

private:
    KeyVal      currentRow;                             // 当前乐器
    maps        instruments;                            // 乐器映射表

    maps        init ();                                // 加载乐器
};

#endif // INSTRUMENT_H
