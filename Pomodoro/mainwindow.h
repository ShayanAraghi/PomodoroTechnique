#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <iostream>
#include <string>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTime time;


private slots:

    void updateTimer();

    void on_StartButton_clicked();


    void on_StopButton_clicked();

    void on_ResetButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;



};

#endif // MAINWINDOW_H
