#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set timer text to 25:00
    ui->label->setText("25:00");

    //set timer to 25:00
    time.setHMS(0,25,0);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTimer()
{
    time = time.addSecs(-1);
    ui->label->setText(time.toString("m:ss"));

    if(ui->label->text() == "0:00"){
        timer->stop();

        //add another X into the number of Sessions
       QString numSessions = ui->numSession->text();
       numSessions = numSessions + "X";

       ui->numSession->setText(numSessions);

       //set timer to 5 minute break
       time.setHMS(0,5,00);

       //set timer text to 25:00
       ui->label->setText("5:00");


    }

}


void MainWindow::on_StartButton_clicked()
{

    timer->start(1000);

}




void MainWindow::on_StopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_ResetButton_clicked()
{
    //stop the timer
    timer->stop();

    //count how many sessions the user has had.
    QString numSessions = ui->numSession->text();
    int sessions = numSessions.length() + 1;

    if(sessions % 5 != 0){
        //if the number of sessions does divide by 4 evenly. set timer to 25:00 (regular study time)
    //set timer to 25 minutes
    time.setHMS(0,25,00);

    //set timer text to 25:00
    ui->label->setText("25:00");

    } else{
        //else set to extended break
        //set timer to 30 minutes
        time.setHMS(0,30,00);

        //set timer text to 25:00
        ui->label->setText("30:00");


    }

}
