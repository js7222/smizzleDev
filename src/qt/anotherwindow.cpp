#include "anotherwindow.h"
#include "ui_anotherwindow.h"
#include <QDebug>

AnotherWindow::AnotherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnotherWindow)
{
    ui->setupUi(this);
}

AnotherWindow::~AnotherWindow()
{
    delete ui;
}

void AnotherWindow::on_pushButton_clicked()
{
    qDebug() << "button pressed";
}
