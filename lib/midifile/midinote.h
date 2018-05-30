#ifndef MIDINOTE_H
#define MIDINOTE_H

class MidiNote
{
public:
    MidiNote();

    short       pitch;                      // 音高
    short       duration;                   // 时值
    char        signPitch;                  // 简谱标记的音高 (0-7, 包含#和b)
    char        signOctave;                 // 简谱标记的八度 (0为中音, 大于0为高音, 小于0为低音)
    float       signDuration;               // 简谱标记的时值 (1为四分音符, 0.5为八分音符……)

    bool        turnUpPitch         ();     // 提升1个音高
    bool        turnDownPitch       ();     // 降低1个音高
    bool        turnUpOctave        ();     // 提升1个八度
    bool        turnDownOctave      ();     // 降低1个八度
    bool        turnUpDuration      ();     // 增大1个单位时值
    bool        turnDownDUration    ();     // 减小1个单位时值
    bool        setPuaseSymbol      ();     // 将音符设置为休止符
};

#endif // MIDINOTE_H
