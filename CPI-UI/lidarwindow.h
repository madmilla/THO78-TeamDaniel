#ifndef LIDARWINDOW_H
#define LIDARWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "lidar.h"

namespace Ui {
class lidarwindow;
}

class lidarwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit lidarwindow(lidar * l, QWidget *parent = 0);
    ~lidarwindow();

private slots:


    void handleButtonLidar();

    void setRpm(int Rpm);
    void timerPassed();

private:
    void lidarMissionRunning(bool isRunning);
    QTimer * timer;
    Ui::lidarwindow *ui;

    lidar * l;
};

#endif // LIDARWINDOW_H
