#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logicwork.h"

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
    void keyPressEvent(QKeyEvent*);

private:
    Ui::MainWindow *ui;
    LogicWork logicWork;
    bool _initPaint = true;
    QImage ImagePvoLevelOne, ImagePvoLevelTwo, ImagePvoLevelThree;

signals:
    void signalSelectAlgoritm(Alg);
private slots:
    void slotClickedSelectAlgoritm();
};
#endif // MAINWINDOW_H
