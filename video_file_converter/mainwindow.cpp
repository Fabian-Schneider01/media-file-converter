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

    if (ui->MPThreeRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::MPThree)) {
            QMessageBox::information(this, "Conversion Success", "File converted to MP3 successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->AACRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::AAC)) {
            QMessageBox::information(this, "Conversion Success", "File converted to AAC successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WAVRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::WAV)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WAV successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->OGGRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::OGG)) {
            QMessageBox::information(this, "Conversion Success", "File converted to OGG successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->FLACRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::FLAC)) {
            QMessageBox::information(this, "Conversion Success", "File converted to FLAC successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->WMARadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::WMA)) {
            QMessageBox::information(this, "Conversion Success", "File converted to WMA successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->AIFFRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::AIFF)) {
            QMessageBox::information(this, "Conversion Success", "File converted to AIFF successfully!");
        } else {
            QMessageBox::warning(this, "Conversion Error", "Failed to convert file.");
        }
    } else if (ui->AMRRadioButton->isChecked()) {
        if (ffmpegHandler.convertToAudioFormat(inputFilePath, ffmpegHandler.getInputFile(inputFilePath), FFmpegHandler::AudioFormat::AMR)) {
            QMessageBox::information(this, "Conversion Success", "File converted to AMR successfully!");
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
