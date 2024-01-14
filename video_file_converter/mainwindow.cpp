#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::convertButtonClicked);
    connect(ui->openFolder, &QPushButton::clicked, this, &MainWindow::openFolderClicked);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleComboBoxChange(int)));
    ui->videoWidget->show();
    ui->audioWidget->hide();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::convertButtonClicked() {
    QString inputFilePath = ui->lineEdit->text();

    //video formats
    if (ui->MPFourRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::MPFour)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MP4 successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->AVIRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::AVI)) {
            QMessageBox::information(this, "Conversion Success", "File converted to AVI successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->MOVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::MOV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MOV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->MKVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::MKV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MKV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WebMRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::WebM)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WebM successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->FLVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::FLV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to FLV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WMVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::WMV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WMV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->ThreeGPRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::ThreeGP)) {
            QMessageBox::information(this, "Conversion Success", "File converted to 3GP successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    }

    //audio formats
    if (ui->MPFourRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::MPThree)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MP4 successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->AVIRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::AVI)) {
            QMessageBox::information(this, "Conversion Success", "File converted to AVI successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->MOVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::MOV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MOV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->MKVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::MKV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MKV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WebMRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::WebM)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WebM successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->FLVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::FLV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to FLV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WMVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::WMV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WMV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->ThreeGPRadioButton->isChecked()) {
        if (ffmpegHandler.convertToVideoFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::VideoFormat::ThreeGP)) {
            QMessageBox::information(this, "Conversion Success", "File converted to 3GP successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    }
}

void MainWindow::openFolderClicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("All Files (*);;Text Files (*.txt)"));

    if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        inputFilePath = filePath;
        ui->lineEdit->setText(inputFilePath);
    } else {
        qDebug() << "No file selected.";
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
