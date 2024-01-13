#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ffmpeghandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertButtonClicked();

private:
    Ui::MainWindow *ui;
    FFmpegHandler ffmpegHandler;  // Instance of FFmpegHandler
};

#endif // MAINWINDOW_H
