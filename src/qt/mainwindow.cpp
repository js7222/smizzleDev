
#include <mainwindow.h>
#include <ui_dialog.h>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout();
    m_label = new QLabel(tr("Smizzle Label"));
    QPushButton* pushButton = new QPushButton();
    pushButton->setText("Button");
    m_label->setAlignment(Qt::AlignHCenter);
    layout->addWidget(m_label, 0, 0);
    layout->addWidget(pushButton, 0, 1);
    
    setLayout(layout);
    connect(pushButton, SIGNAL(pressed()), m_label, SLOT(hide()));
    
}

MainWindow::~MainWindow()
{
}
