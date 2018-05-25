#include "main_fr.h"
#include "ui_main_fr.h"

Main_FR::Main_FR(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_FR)
{
    ui->setupUi(this);
    ui->map->load(QUrl(QStringLiteral("file:///Users/janus/project_repo/Pfaffnick/UI/google-map.html")));
    ui->map->show();
}

Main_FR::~Main_FR()
{
    delete ui;
}

void Main_FR::on_msgBtn_clicked()
{
    mw.owner = user;
    mw.cdbm = cdbm;
    mw.mdbm = mdbm;
    mw.show();
    mw.displayList();
}


void Main_FR::on_newsBtn_clicked()
{
    nw.rdbm = rdbm;
    nw.displayList();
     nw.show();
}
