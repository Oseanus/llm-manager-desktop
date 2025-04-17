#include "LlmManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWidget window;
    window.setWindowTitle("LLM Manager");  // Set the window title
    window.resize(800, 600);  // Set the initial window size to 800x600 pixels
    window.show();

    return app.exec();
}