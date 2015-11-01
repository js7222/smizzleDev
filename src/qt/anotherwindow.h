#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = 0);
    ~AnotherWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AnotherWindow *ui;
};

#endif // ANOTHERWINDOW_H
