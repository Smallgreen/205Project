#include "main_ep.h"
#include "ui_main_ep.h"

Main_EP::Main_EP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_EP)
{
    ui->setupUi(this);
    ui->map->load(QUrl(QStringLiteral("file:///Users/janus/project_repo/Pfaffnick/UI/google-map.html")));
    ui->map->show();
}

Main_EP::~Main_EP()
{
    delete ui;
}

void Main_EP::on_msgBtn_clicked()
{
    mw.owner = user;
    mw.cdbm = cdbm;
    mw.mdbm = mdbm;
    mw.show();
    mw.displayList();

}

void Main_EP::on_SimBtn_clicked()
{
    sw.show();
}

void Main_EP::on_repBtn_clicked()
{
    aw.rdbm = rdbm;
    aw.displayList();
    aw.show();
}
