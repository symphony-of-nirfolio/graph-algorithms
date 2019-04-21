#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "graphwindow.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLegendMarker>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GraphWindow* window;

public slots:
    void show_graph_window();
};

#endif // MAINWINDOW_H
