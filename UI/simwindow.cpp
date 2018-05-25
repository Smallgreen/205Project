#include "simwindow.h"
#include "ui_simwindow.h"

SimWindow::SimWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimWindow)
{
    ui->setupUi(this);
}

SimWindow::~SimWindow()
{
    delete ui;
}

void SimWindow::on_startBtn_clicked()
{

}
