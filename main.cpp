    #include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Apply dark theme stylesheet
    // a.setStyleSheet(
    //     "QMainWindow, QWidget {"
    //     "    background-color: #2b2b2b;"
    //     "    color: #ffffff;"
    //     "}"
    //     "QMenuBar {"
    //     "    background-color: #3c3c3c;"
    //     "    color: #ffffff;"
    //     "}"
    //     "QMenuBar::item {"
    //     "    background-color: transparent;"
    //     "    padding: 4px 8px;"
    //     "}"
    //     "QMenuBar::item:selected {"
    //     "    background-color: #505050;"
    //     "}"
    //     "QMenu {"
    //     "    background-color: #3c3c3c;"
    //     "    color: #ffffff;"
    //     "    border: 1px solid #505050;"
    //     "}"
    //     "QMenu::item:selected {"
    //     "    background-color: #505050;"
    //     "}"
    //     "QToolBar {"
    //     "    background-color: #3c3c3c;"
    //     "    border: none;"
    //     "    spacing: 3px;"
    //     "}"
    //     "QToolButton {"
    //     "    background-color: transparent;"
    //     "    color: #ffffff;"
    //     "    padding: 4px;"
    //     "}"
    //     "QToolButton:hover {"
    //     "    background-color: #505050;"
    //     "}"
    //     "QToolButton:pressed {"
    //     "    background-color: #606060;"
    //     "}"
    //     "QStatusBar {"
    //     "    background-color: #3c3c3c;"
    //     "    color: #ffffff;"
    //     "}"
    // );

    MainWindow w;
    w.show();
    return a.exec();
}
