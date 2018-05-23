#include "instrument.h"

Instrument::Instrument()
{

}

// 通过乐器 ID 获取乐器名称
QString Instrument::getInstrumentName(short instrument_id)
{
    if (instrument_id < 0 || instrument_id > instruments.count())
        return "";
    else
        return instruments[instrument_id];
}

// 通过乐器名称获取乐器 ID
short Instrument::getInstrumentId(QString instrument_name)
{
    short result = 0, i;
    for (i = 0; i < instruments.count(); i++) {
        if (instruments[i] == instrument_name) {
            result = i;
            break;
        }
    }

    return result;
}

// 设定为特定乐器
void Instrument::setInstrument(short instrument_id)
{
    currentInstrumentId = instrument_id;
    currentInstrumentId = instrument_id < 0 ? instruments.count() - 1 : currentInstrumentId;
    currentInstrumentId = instrument_id >= instruments.count() ? 0 : currentInstrumentId;
    currentInstrumentName = instruments[currentInstrumentId];
}

// 切换为上一个或下一个乐器(显示在 QPushButton 组件上)
void Instrument::switchoverInstrument(short operate_type, QPushButton *show_btn)
{
    short instrument_id = currentInstrumentId;
    instrument_id += operate_type > 0 ? 1 : 0;
    instrument_id -= operate_type < 0 ? 1 : 0;
    setInstrument(instrument_id);
    QPushButton *btn = show_btn;
    btn->setText(currentInstrumentName);
}
