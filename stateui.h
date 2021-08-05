#ifndef STATEUI_H
#define STATEUI_H

#include <QWidget>

namespace Ui {
class StateUi;
}

class StateUi : public QWidget
{
    Q_OBJECT

public:
    explicit StateUi(QWidget *parent = nullptr);
    ~StateUi();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::StateUi *ui;
};

#endif // STATEUI_H
