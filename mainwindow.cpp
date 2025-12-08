#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
}

MainWindow::~MainWindow() {}

void MainWindow::on_actionOpen_clicked()
{
    // Prompt user to select file to open
    QString filePath = QFileDialog::getOpenFileName(this,
        tr("開啟檔案"),
        "",
        tr("文字檔案 (*.txt);;所有檔案 (*.*)"));
    
    // User cancelled the dialog
    if (filePath.isEmpty()) {
        return;
    }
    
    // Open and read the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("開啟檔案"),
            tr("無法開啟檔案 %1:\n%2")
            .arg(filePath)
            .arg(file.errorString()));
        return;
    }
    
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString content = in.readAll();
    file.close();
    
    // Set the content to textEdit and update current file path
    textEdit->setPlainText(content);
    currentFilePath = filePath;
    
    // Show success message in status bar
    statusbar->showMessage(tr("檔案已開啟: %1").arg(currentFilePath), 3000);
}

void MainWindow::on_actionSave_clicked()
{
    // If no current file path, prompt user to select save location
    if (currentFilePath.isEmpty()) {
        currentFilePath = QFileDialog::getSaveFileName(this,
            tr("儲存檔案"),
            "",
            tr("文字檔案 (*.txt);;所有檔案 (*.*)"));
        
        // User cancelled the dialog
        if (currentFilePath.isEmpty()) {
            return;
        }
    }
    
    // Save the text content to file
    QFile file(currentFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("儲存檔案"),
            tr("無法儲存檔案 %1:\n%2")
            .arg(currentFilePath)
            .arg(file.errorString()));
        return;
    }
    
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << textEdit->toPlainText();
    file.close();
    
    // Show success message in status bar
    statusbar->showMessage(tr("檔案已儲存: %1").arg(currentFilePath), 3000);
}
