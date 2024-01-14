#ifndef FFMPEGHANDLER_H
#define FFMPEGHANDLER_H

#include <QString>
#include <QDebug>

class FFmpegHandler
{
public:
    enum VideoFormat {
        MPFour,
        AVI,
        MOV,
        MKV,
        WebM,
        FLV,
        WMV,
        ThreeGP,
    };

    enum AudioFormat {
        MPThree,
        AAC,
        WAV,
        OGG,
        FLAC,
        WMA,
        AIFF,
        AMR,
    };

    FFmpegHandler();
    ~FFmpegHandler();

    bool convertToVideoFormat(const QString &inputFilePath, const QString &fileName, const VideoFormat &format);
    bool convertToAudioFormat(const QString &inputFilePath, const QString &fileName, const AudioFormat &format);
    QString pathParser(const QString &inputFilePath, const QString &fileName, const bool &getDirectory);
    QString getInputFile(const QString &inputFilePath);
};

#endif // FFMPEGHANDLER_H
