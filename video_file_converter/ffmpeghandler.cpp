#include "ffmpeghandler.h"
#include <iostream>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

FFmpegHandler::FFmpegHandler() {
}

FFmpegHandler::~FFmpegHandler() {
}

bool FFmpegHandler::convertToVideoFormat(const QString &inputFilePath, const QString &fileName, const VideoFormat &format) {
    QStringList ffmpegArgs;
    switch(format) {
        case MPFour:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mp4";
            break;
        case AVI:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".avi";
            break;
        case MOV:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mov";
            break;
        case MKV:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mkv";
            break;
        case WebM:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".webm";
            break;
        case FLV:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".flv";
            break;
        case WMV:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".wmv";
            break;
        case ThreeGP:
            ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".3gp";
            break;
    }

    QProcess ffmpegProcess;
    ffmpegProcess.setProgram("ffmpeg");
    ffmpegProcess.setArguments(ffmpegArgs);

    ffmpegProcess.setWorkingDirectory(pathParser(inputFilePath, fileName, true));

    ffmpegProcess.start();
    ffmpegProcess.waitForFinished();

    return (ffmpegProcess.exitCode() == 0);
}

bool FFmpegHandler::convertToAudioFormat(const QString &inputFilePath, const QString &fileName, const AudioFormat &format) {
    QStringList ffmpegArgs;
    switch(format) {
    case MPThree:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".mp3";
        break;
    case AAC:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".aac";
        break;
    case WAV:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".wav";
        break;
    case OGG:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".ogg";
        break;
    case FLAC:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".flac";
        break;
    case WMA:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".wma";
        break;
    case AIFF:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".aiff";
        break;
    case AMR:
        ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName, false) + ".amr";
        break;
    }

    QProcess ffmpegProcess;
    ffmpegProcess.setProgram("ffmpeg");
    ffmpegProcess.setArguments(ffmpegArgs);

    ffmpegProcess.setWorkingDirectory(pathParser(inputFilePath, fileName, true));

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

