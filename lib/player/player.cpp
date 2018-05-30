#include "player.h"

Player::Player()
{

}

// 加载 MIDI 文件
bool Player::load (int index)
{

}


// 播放 (可指定播放位置)
void Player::play (int position)
{

}

// 暂停播放
void Player::pause ()
{

}

// 停止播放
void Player::stop ()
{

}

// 上一曲
void Player::lastSong ()
{

}

// 下一曲
void Player::nextSong ()
{

}

// 设置音轨的音量 (0表示设置所有音轨)
bool Player::setVolume (int track, char volume)
{
    if (track < 0 || track > midi->trackCount())
        return false;
    if (volume < 0 || volume > 127)
        return false;

    if (track == 0)
        play_volume = volume;
    else
        *(tracks_volume+track) = volume;
    return true;
}

// 设置变调
bool Player::setTone (char tone)
{
    if (tone < -36 || tone > 36)
        return false;

    play_tone = tone;
    return true;
}

// 设置速度
bool Player::setVelocity (char velocity)
{
    if (velocity <= 0 || velocity > 127)
        return false;

    play_velocity = velocity;
    return true;
}

// 获取当前 tick (播放进度)
int Player::tick ()
{
    return currentTick;
}

// 获取总 tick 数
int Player::totalTick ()
{
    return midi->tickCount();
}

// 获取当前播放状态 (0=未知, 1=播放中, 2=暂停中, 3=已停止)
int Player::status ()
{
    return currentStatus;
}
