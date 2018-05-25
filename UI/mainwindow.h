#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "../database/reportdb.h"
#include "logindlg.h"
#include "registerdlg.h"
#include "main_fr.h"
#include "main_ep.h"
#include "main_ctz.h"
#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setDB(dbmanager *db, contactlistDB *cdb, msgDB *mdb, reportDB *rdb);

private slots:

    void on_loginBtn_clicked();

    void on_regBtn_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap image;

    RegisterDlg r;
    loginDlg l;
    Main_FR mainf;
    Main_EP maine;
    Main_CTZ mainc;
};

#endif // MAINWINDOW_H
