#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("LLM Manager");  // Set the window title
    window.resize(800, 600);  // Set the initial window size to 800x600 pixels

    QHBoxLayout *mainLayout = new QHBoxLayout;

    // Left column layout
    QWidget *leftColumn = new QWidget;
    QVBoxLayout *leftLayout = new QVBoxLayout(leftColumn);
    
    QComboBox *llmMenu = new QComboBox();
    llmMenu->addItem("Item 1");
    llmMenu->addItem("Item 2");
    llmMenu->addItem("Item 3");
    leftLayout->addWidget(llmMenu);
    
    leftLayout->addWidget(new QLabel("Left Column Widget 1"));
    leftColumn->setFixedWidth(150);  // Set fixed width for left column

    // Middle column layout
    QVBoxLayout *middleLayout = new QVBoxLayout;
    middleLayout->addWidget(new QLabel("Middle Column Widget 1"));

    // Right column layout
    QWidget *rightColumn = new QWidget;
    QVBoxLayout *rightLayout = new QVBoxLayout(rightColumn);
    rightLayout->addWidget(new QLabel("Right Column Widget 1"));
    rightColumn->setFixedWidth(150);  // Set fixed width for right column

    // Add column layouts to the main layout
    mainLayout->addWidget(leftColumn);  // Fixed width column
    mainLayout->addLayout(middleLayout); // Flexible width column
    mainLayout->addWidget(rightColumn);  // Fixed width column

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}