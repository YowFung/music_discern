#include "instrument.h"

Instrument::Instrument()
{
    instruments = init();
    currentRow = instruments.begin();
}

// 加载乐器
QMap<char, QString> Instrument::init()
{
    QMap<char, QString> map;
    map[0] = "声学大钢琴";
    map[2] = "电钢琴";
    map[8] = "钢片琴";
    map[9] = "钟琴";
    map[10] = "八音盒";
    map[11] = "颤音琴";
    map[12] = "马林巴";
    map[13] = "木琴";
    map[15] = "大扬琴";
    map[21] = "手风琴";
    map[22] = "口琴";
    map[24] = "尼龙弦吉他";
    map[25] = "钢弦吉他";
    map[26] = "爵士电吉他";
    map[27] = "清音电吉他";
    map[32] = "声学大贝司";
    map[33] = "指弹电贝司";
    map[34] = "拨片电贝司";
    map[38] = "电子合成贝司";
    map[40] = "小提琴";
    map[42] = "大提琴";
    map[46] = "竖琴";
    map[56] = "小号";
    map[60] = "圆号";
    map[68] = "双簧管";
    map[71] = "黑管";
    map[72] = "短笛";
    map[74] = "竖笛";
    map[75] = "排箫";
    map[108] = "卡林巴";
    map[114] = "钢鼓";

    return map;
}

// 通过乐器 ID 获取乐器名称 (空字符串则表示该乐器不存在)
QString Instrument::getName (char id)
{
    if (!instruments.contains(id))
        return "";

    return instruments[id];
}

// 通过乐器名称获取乐器 ID (-1则表示该乐器不存在)
char Instrument::getId (QString name)
{
    KeyVal it;
    for (it = instruments.begin(); it != instruments.end(); it++) {
        if (it.value() == name)
            return it.key();
    }

    return -1;
}

//// 通过索引获取乐器对象 (键值对)
//KeyVal Instrument::getInstrument (int index)
//{
//    if (index < 0 || index > instruments::count())
//        return nullptr;

//    KeyVal it = instruments.begin();
//    int i;
//    for (i = 0; i < instruments::count(); i++) {
//        if (i == index)
//            return it;
//        else
//            it++;
//    }

//    return nullptr;
//}

// 获取乐器总数
int Instrument::count ()
{
    return instruments.count();
}

// 乐器 id 是否存在
bool Instrument::isExisting(char id)
{
    return instruments.contains(id);
}

// 乐器名称是否存在
bool Instrument::isExisting(QString name)
{
    KeyVal it;
    for (it = instruments.begin(); it != instruments.end(); it++) {
        if (it.value() == name)
            return true;
    }

    return false;
}

// 切换乐器 (TURN_UP | TURN_DOWN)
QString Instrument::turnInstrument (char turn_type)
{
    if (turn_type != TURN_UP && turn_type != TURN_DOWN)
        return "";

    KeyVal it = currentRow;
    if (it == instruments.begin())
        it = instruments.end();
    else if (it == instruments.end())
        it = instruments.begin();
    else
        it += (int)turn_type;

    currentRow = it;
    return currentRow.value();
}
                            

//// 通过乐器 ID 获取乐器名称
//QString Instrument::getInstrumentName(short instrument_id)
//{
//    if (instrument_id < 0 || instrument_id > instruments.count())
//        return "";
//    else
//        return instruments[instrument_id];
//}

//// 通过乐器名称获取乐器 ID
//short Instrument::getInstrumentId(QString instrument_name)
//{
//    short result = 0, i;
//    for (i = 0; i < instruments.count(); i++) {
//        if (instruments[i] == instrument_name) {
//            result = i;
//            break;
//        }
//    }

//    return result;
//}

//// 设定为特定乐器
//void Instrument::setInstrument(short instrument_id)
//{
//    currentInstrumentId = instrument_id;
//    currentInstrumentId = instrument_id < 0 ? instruments.count() - 1 : currentInstrumentId;
//    currentInstrumentId = instrument_id >= instruments.count() ? 0 : currentInstrumentId;
//    currentInstrumentName = instruments[currentInstrumentId];
//}

//// 切换为上一个或下一个乐器(显示在 QPushButton 组件上)
//void Instrument::switchoverInstrument(short operate_type, QPushButton *show_btn)
//{
//    short instrument_id = currentInstrumentId;
//    instrument_id += operate_type > 0 ? 1 : 0;
//    instrument_id -= operate_type < 0 ? 1 : 0;
//    setInstrument(instrument_id);
//    QPushButton *btn = show_btn;
//    btn->setText(currentInstrumentName);
//}
