#ifndef STATEUI_H
#define STATEUI_H

#include <QWidget>
#include <QLabel>
#include "enviropment.h"

namespace Ui {
class StateUi;
}

class StateUi : public QWidget
{
    Q_OBJECT

public:
    explicit StateUi(QWidget *parent = nullptr);
    ~StateUi();
    void SetTextLabel(QString str);
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::StateUi *ui;
    QLabel* lbl;
    int XYst;
};

#endif // STATEUI_H
