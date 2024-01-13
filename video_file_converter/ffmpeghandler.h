#ifndef FFMPEGHANDLER_H
#define FFMPEGHANDLER_H

#include <QString>
#include <QDebug>
#include <iostream>

class FFmpegHandler
{
public:
    FFmpegHandler();
    ~FFmpegHandler();

    bool convertToMP4(const QString &inputFilePath, const QString &fileName);
    QString pathParser(const QString &inputFilePath, const QString &fileName);
};

#endif // FFMPEGHANDLER_H
