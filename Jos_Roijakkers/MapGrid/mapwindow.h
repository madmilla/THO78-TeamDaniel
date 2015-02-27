#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget * MainWindow, QWidget *parent = 0);
    ~MapWindow();

private slots:
    void on_actionSave_triggered();

    void closeEvent (QCloseEvent *event);

    void on_Empty_radioButton_toggled(bool checked);

    void on_Obstacle_radioButton_toggled(bool checked);

    void on_Quadcopter_radioButton_toggled(bool checked);

    void on_ATV_radioButton_toggled(bool checked);

    void on_Rosbee_radioButton_toggled(bool checked);

    void on_randomButton_clicked();



private:
    Ui::MapWindow *ui;
    QWidget *MainWindow;
    const int cellsX = 20;
    const int cellsY = 20;
    const QString fileName = "Maps";
    QJsonObject json;
};

#endif // MAPWINDOW_H
