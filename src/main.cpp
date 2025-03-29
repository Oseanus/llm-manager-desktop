#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("My Qt Application");

    QPushButton button("Click Me", &mainWindow);
    button.setGeometry(100, 100, 100, 30);

    mainWindow.show();

    return app.exec();
}