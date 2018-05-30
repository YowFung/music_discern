#ifndef MIDITRACK_H
#define MIDITRACK_H

#include "midinote.h"

// 音符链表结构体
struct note
{
    int             id;                                     // 音符 ID
    MidiNote        note;                                   // 音符信息
    struct notes*   next;                                   // 下一音符地址
};

// MidiTrack 类
class MidiTrack
{
public:
    MidiTrack();

    bool        append      (MidiNote note);                // 向音轨追加音符
    bool        destroy     ();                             // 清除所有音符
    bool        insert      (int note_id, MidiNote note);   // 在指定 id 后面插入音符
    bool        del         (int note_id, MidiNote note);   // 删除指定 id 的音符
    int         count       ();                             // 获取该音轨的音符总数
    MidiNote    note        (int note_id);                  // 获取指定 id 的音符

private:
    struct note*    head       = nullptr;                   // 音符链表头地址
};

#endif // MIDITRACK_H
