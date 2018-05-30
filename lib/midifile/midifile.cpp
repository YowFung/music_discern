#include "midifile.h"

MidiFile::MidiFile()
{

}

// 加载 MIDI 文件
bool MidiFile::loadFile(QString filename)
{

}

// 写入 MIDI 文件
bool MidiFile::saveFile(QString filename)
{

}

// 获取 MIDI 文件信息
struct fileInfo MidiFile::MidiInfo()
{

}

// 获取指定 id 的音轨
MidiTrack MidiFile::getTrack(int track_id)
{

}

// 向 MIDI 文件追加音轨
bool MidiFile::appendTrack(MidiTrack track)
{

}

// 删除指定 id 的音轨
bool MidiFile::delTrack (int track_id)
{

}

// 在指定 id 后面插入音轨
bool MidiFile::insertTrack (int track_id, MidiTrack track)
{

}

// 获取音轨总数
int MidiFile::trackCount ()
{
	
}

// 获取 Tick 总数
int MidiFile::tickCount()
{

}

// 设置文件保存的路径
bool MidiFile::setFileName (QString path)
{

}

// 设置歌曲名
bool MidiFile::setSongTitle (QString title)
{
    if (title.isEmpty() || title.length() > 100)
        return false;

    midi_info.songTitle = title;
    return true;
}

// 设置默认乐器
bool MidiFile::setInstrument (char instrument_id)
{

}

// 设置默认速度
bool MidiFile::setVelocity (char velocity)
{

}

// 设置默认变调
bool MidiFile::setTone (char tone)
{

}

// 是否为有效的 MIDI 文件
bool MidiFile::isValidFile ()
{
	
}
