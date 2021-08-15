#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Objects/state.h"
#include "Objects/pvo.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    std::vector <State> states;
    std::vector <Pvo> pvoes;
    int sizeX;
    int sizeY;
    int xGrid;
    int yGrid;
};
#endif // MAINWINDOW_H
