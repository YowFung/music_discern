#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include "stdlib.h"
#include "../midifile/midifile.h"

// 项目链表结构体
struct item
{
    int             id;                                     // 项目 ID
    MidiFile        midi;                                   // 项目 MIDI 文件
    struct item*    next        = nullptr;                  // 下一个项目地址
};

// 播放列表类
class PlayList
{
public:
    PlayList();
    ~PlayList();

    int             count       ();                         // 获取项目总数
    int             currentRow  ();                         // 获取当前选中项目的 ID
    bool            append      (MidiFile midi);            // 添加项目
    bool            remove      (int index);                // 移除项目
    bool            selected    (int index);                // 选中项目
    void            loadList    ();                         // 加载播放列表
    void            saveList    ();                         // 保存播放列表

private:
    QString         listfile    = "/config/playlist.json";  // 播放列表存档文件路径
    struct item*    currentItem = nullptr;                  // 当前选中的项目
    struct item*    items       = nullptr;                  // 项目链表地址

    void            reload      ();                         // 重新给项目编号

};

#endif // PLAYLIST_H
