#include "ffmpeghandler.h"
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>

FFmpegHandler::FFmpegHandler() {
    // Constructor implementation
}

FFmpegHandler::~FFmpegHandler() {
    // Destructor implementation
}

bool FFmpegHandler::convertToMP4(const QString &inputFilePath, const QString &fileName) {
    // Construct the FFmpeg command
    QStringList ffmpegArgs;
    ffmpegArgs << "-i" << inputFilePath << "-c:v" << "libx264" << "-c:a" << "aac" << pathParser(inputFilePath, fileName);

    QProcess ffmpegProcess;
    ffmpegProcess.setProgram("ffmpeg");
    ffmpegProcess.setArguments(ffmpegArgs);

    // Set the working directory to the application's directory
    ffmpegProcess.setWorkingDirectory(inputFilePath);

    // Start the process
    ffmpegProcess.start();
    ffmpegProcess.waitForFinished();

    // Check if the process executed successfully (exit code 0)
    return (ffmpegProcess.exitCode() == 0);
}


QString FFmpegHandler::pathParser(const QString &inputFilePath, const QString &fileName) {
    QString outputPath = "";
    for (int i = inputFilePath.length() - 1; i >= 0; i--) {
        if (inputFilePath[i] == '/') {
            outputPath = inputFilePath.left(i);
            break;
        }
    }
    outputPath.append('/' + fileName);
    std::cout << "parsed and written to: " << outputPath.toStdString() << std::endl;
    return outputPath;
}

