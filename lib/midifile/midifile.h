#ifndef MIDIFILE_H
#define MIDIFILE_H

#include <QString>
#include <QString>
#include "miditrack.h"

// 音轨链表结构体
struct track
{
    int             id;                                                 // 音轨 ID
    MidiTrack       track;                                              // 音轨信息
    struct track*   next;                                               // 下一音轨地址
};

// MIDI 文件信息结构体
struct fileInfo
{
    QString         fileName        = "";                               // 文件名
    QString         filePath        = "";                               // 文件路径
    QString         songTitle       = "";                               // 曲名
    char            instrument      = 0;                                // 乐器
    char            velocity        = 78;                               // 速度
    char            modifiedTone    = 0;                                // 变调
    int             tranksCount     = 0;                                // 音轨数
    int             ticksCount      = 0;                                // tick 数
};

// MidiFile 类
class MidiFile
{
public:
    MidiFile();

    bool            loadFile        (QString filename);                 // 加载 MIDI 文件
    bool            saveFile        (QString filename = "");            // 写入 MIDI 文件
    struct fileInfo MidiInfo        ();                                 // 获取 MIDI 文件信息
    MidiTrack       getTrack        (int track_id);                     // 获取指定 id 的音轨
    bool            appendTrack     (MidiTrack track);                  // 向 MIDI 文件追加音轨
    bool            delTrack        (int track_id);                     // 删除指定 id 的音轨
    bool            insertTrack     (int track_id, MidiTrack track);    // 在指定 id 后面插入音轨
    int             trackCount      ();                                 // 获取音轨总数
    int             tickCount       ();                                 // 获取 Tick 总数
    bool            setFileName     (QString path);                     // 设置文件保存的路径
    bool            setSongTitle    (QString title);                    // 设置歌曲名
    bool            setInstrument   (char instrument_id);               // 设置默认乐器
    bool            setVelocity     (char velocity);                    // 设置默认速度
    bool            setTone         (char tone);                        // 设置默认变调
    bool            isValidFile     ();                                 // 是否为有效的 MIDI 文件

private:
    struct fileInfo midi_info;                                          // MIDI 文件信息
    struct track    *tracks = nullptr;                                  // MIDI 音轨链表
};

#endif // MIDIFILE_H
