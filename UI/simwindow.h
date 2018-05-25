#ifndef SIMWINDOW_H
#define SIMWINDOW_H

#include <QMainWindow>

namespace Ui {
class SimWindow;
}

class SimWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimWindow(QWidget *parent = 0);
    ~SimWindow();

private slots:
    void on_startBtn_clicked();

private:
    Ui::SimWindow *ui;
};

#endif // SIMWINDOW_H
