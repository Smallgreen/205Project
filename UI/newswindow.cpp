#include "newswindow.h"
#include "ui_newswindow.h"

NewsWindow::NewsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
}

NewsWindow::~NewsWindow()
{
    delete ui;
}

void NewsWindow::on_refreshBtn_clicked()
{
    displayList();
}

void NewsWindow::displayList(){
    ui->newsList->setText("");
    QStringList vList = rdbm->getVerifiedAlert();
    foreach(QString v, vList){
        ui->newsList->append(v);
    }
}

void NewsWindow::on_verifyBtn_clicked()
{
    vw.rdbm = rdbm;
    vw.displayList();
    vw.show();
}
