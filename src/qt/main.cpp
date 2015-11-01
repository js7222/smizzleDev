#include <QApplication>
#include <QTextEdit>
#include <anotherwindow.h>

int main(int argv, char **args)
{
    QApplication app(argv, args);

    AnotherWindow window;
    window.show();

    return app.exec();
}
