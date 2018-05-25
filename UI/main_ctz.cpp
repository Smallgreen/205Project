#include "main_ctz.h"
#include "ui_main_ctz.h"
#include <QStringList>
#include <qstring.h>
#include <QMessageBox>

Main_CTZ::Main_CTZ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_CTZ)
{
    ui->setupUi(this);
    ui->map->load(QUrl(QStringLiteral("file:///Users/janus/project_repo/Pfaffnick/UI/google-map.html")));
    ui->map->show();
}

Main_CTZ::~Main_CTZ()
{
    delete ui;
}

void Main_CTZ::on_disBtn_clicked()
{
    QMessageBox::warning(this, tr("warning"), tr("distress now?"), QMessageBox::Yes);
}

void Main_CTZ::on_repBtn_clicked()
{
    rdlg.rdbm = rdbm;
    rdlg.user = user;
    rdlg.show();
}

void Main_CTZ::on_newsBtn_clicked()
{
    nw.rdbm = rdbm;
    nw.displayList();
    nw.show();
}
