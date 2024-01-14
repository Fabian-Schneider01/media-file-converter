#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect the convert button's clicked signal to the custom slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::convertButtonClicked);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleComboBoxChange(int)));
    ui->videoWidget->show();
    ui->audioWidget->hide();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::convertButtonClicked() {
    // Get the text from the line edit
    QString inputFilePath = ui->lineEdit->text();

    // Check if the mp4 radio button is checked
    if (ui->radioButton->isChecked()) {
        // Set the output file path (modify this based on your needs)
        QString fileName = "output.mp4";

        // Call FFmpegHandler to perform the conversion
        if (ffmpegHandler.convertToMP4(inputFilePath, fileName)) {
            QMessageBox::information(this, "Conversion Success", "File converted successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    }
}

void MainWindow::handleComboBoxChange(int index) {
    if(index == 0) {
        ui->videoWidget->show();
        ui->audioWidget->hide();
    } else {
        ui->videoWidget->hide();
        ui->audioWidget->show();
    }
}
