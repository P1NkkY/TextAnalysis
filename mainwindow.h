#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "textanalyzer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void on_btnAnalyzeText_clicked();

private:
    void fillABC();

    void fillCounters();

private:
    Ui::MainWindow *ui;
    TextAnalyzer* analyzer;
};

#endif // MAINWINDOW_H
