#ifndef SHOWPERFORMANCE_H
#define SHOWPERFORMANCE_H

#include <QMainWindow>

namespace Ui {
class showPerformance;
}

class showPerformance : public QMainWindow
{
    Q_OBJECT

public:
    explicit showPerformance(QWidget *parent = nullptr);
    ~showPerformance();

private:
    Ui::showPerformance *ui;
};

#endif // SHOWPERFORMANCE_H
