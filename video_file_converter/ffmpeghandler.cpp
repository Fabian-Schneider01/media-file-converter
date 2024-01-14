#include "ffmpeghandler.h"
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

FFmpegHandler::FFmpegHandler() {
    // Constructor implementation
}

FFmpegHandler::~FFmpegHandler() {
    // Destructor implementation
}

bool FFmpegHandler::convertToVideoFormat(const QString &inputFilePath, const QString &fileName, const VideoFormat &format) {
    QStringList ffmpegArgs;
    switch(format) {
    case MPFour: ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mp4";
    case MOV: ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mov";
    }


    QProcess ffmpegProcess;
    ffmpegProcess.setProgram("ffmpeg");
    ffmpegProcess.setArguments(ffmpegArgs);

    ffmpegProcess.setWorkingDirectory(pathParser(inputFilePath, fileName, true));

    // Start the process
    ffmpegProcess.start();
    ffmpegProcess.waitForFinished();

    return (ffmpegProcess.exitCode() == 0);
}

QString FFmpegHandler::getInputFile(const QString &inputFilePath) {
    QFileInfo fileInfo(inputFilePath);
    QString fileName = fileInfo.baseName();
    return fileName;
}

QString FFmpegHandler::pathParser(const QString &inputFilePath, const QString &fileName, const bool &getDirectory) {
    QString outputPath = "";
    for (int i = inputFilePath.length() - 1; i >= 0; i--) {
        if (inputFilePath[i] == '/') {
            outputPath = inputFilePath.left(i);
            break;
        }
    }
    getDirectory ? outputPath.append('/') : outputPath.append('/' + fileName);
    std::cout << "parsed and written to: " << outputPath.toStdString() << std::endl;
    return outputPath;
}

