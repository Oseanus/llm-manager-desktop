#include "LlmManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("LLM Manager");  // Set the window title
    window.resize(800, 600);  // Set the initial window size to 800x600 pixels

    QHBoxLayout mainLayout(&window);

    // Left column layout
    QWidget leftColumn;
    QVBoxLayout leftLayout(&leftColumn);
    
    QComboBox *llmMenu = new QComboBox();
    llmMenu->addItem("Item 1");
    llmMenu->addItem("Item 2");
    llmMenu->addItem("Item 3");
    leftLayout.addWidget(llmMenu);
    
    QLabel leftLabel("Left Column Qidget 1");
    leftLayout.addWidget(&leftLabel);
    leftColumn.setFixedWidth(150);  // Set fixed width for left column

    // Middle column layout
    QWidget middleColumn;
    QVBoxLayout middleLayout(&middleColumn);

    QLabel middleLabel("Middle Column Widget 1");
    middleLayout.addWidget(&middleLabel);

    // Right column layout
    QWidget rightColumn;
    QVBoxLayout rightLayout(&rightColumn);

    QLabel rightLabel("Right Column Widget 1");
    rightLayout.addWidget(&rightLabel);
    rightColumn.setFixedWidth(150);  // Set fixed width for right column

    // Add column layouts to the main layout
    mainLayout.addWidget(&leftColumn);  // Fixed width column
    mainLayout.addWidget(&middleColumn); // Flexible width column
    mainLayout.addWidget(&rightColumn);  // Fixed width column

    window.setLayout(&mainLayout);
    window.show();

    return app.exec();
}