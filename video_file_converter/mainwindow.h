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
    void handleComboBoxChange(int index);

private:
    Ui::MainWindow *ui;
    FFmpegHandler ffmpegHandler;
};

#endif // MAINWINDOW_H
