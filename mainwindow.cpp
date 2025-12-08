#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QStringConverter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
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
    out << ui->textEdit->toPlainText();
    file.close();
    
    // Show success message in status bar
    ui->statusbar->showMessage(tr("檔案已儲存: %1").arg(currentFilePath), 3000);
}
