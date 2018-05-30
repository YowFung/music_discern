#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "../midifile/instrument.h"
#include "playlist.h"

class Player
{
public:
    Player();
    PlayList    list;                                           // 播放列表
    Instrument  instrument;                                     // 乐器

    bool        load            (int index);                    // 加载播放列表中的项目
    void        play            (int position = -1);            // 播放 (可指定播放位置)
    void        pause           ();                             // 暂停播放
    void        stop            ();                             // 停止播放
    void        lastSong        ();                             // 上一曲
    void        nextSong        ();                             // 下一曲
    bool        setVolume       (int track, char volume);       // 设置音轨的音量 (0表示设置所有音轨)
    bool        setTone         (char tone);                    // 设置变调
    bool        setVelocity     (char velocity);                // 设置速度
    int         status          ();                             // 获取当前播放状态 (0=未知, 1=播放中, 2=暂停中, 3=已停止)
    int         tick            ();                             // 获取当前播放的 tick (播放进度)
    int         totalTick       ();                             // 获取总 tick 数
    int         index           ();                             // 获取当前播放歌曲在列表中的索引

private:
    char        play_velocity;                                  // 播放速度
    char        play_tone;                                      // 变调
    char        play_volume;                                    // 总音量
    char*       tracks_volume;                                  // 各音轨的音量
    int         currentStatus   = 0;                            // 当前播放状态 (0=未知, 1=播放中, 2=暂停中, 3=已停止)
    int         currentTick     = 0;                            // 当前播放的 tick (播放进度)
    MidiFile*   midi            = nullptr;                      // 正在播放的 MIDI 文件
};

#endif // PLAYER_H
