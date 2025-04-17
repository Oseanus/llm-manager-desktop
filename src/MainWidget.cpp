#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    _mainLayout = new QHBoxLayout(this);

    // Left column layout
    _leftColumn = new QWidget();
    _leftLayout = new QVBoxLayout(_leftColumn);
    
    _llmMenu = new QComboBox();
    _llmMenu->addItem("Item 1");
    _llmMenu->addItem("Item 2");
    _llmMenu->addItem("Item 3");
    _leftLayout->addWidget(_llmMenu);
    
    _leftLabel = new QLabel("Left Column Widget 1");
    _leftLayout->addWidget(_leftLabel);
    _leftColumn->setFixedWidth(150);  // Set fixed width for left column

    // Middle column layout
    _middleColumn = new QWidget();
    _middleLayout = new QVBoxLayout(_middleColumn);

    _middleLabel = new QLabel("Middle Column Widget 1");
    _middleLayout->addWidget(_middleLabel);

    // Right column layout
    _rightColumn = new QWidget();
    _rightLayout = new QVBoxLayout(_rightColumn);

    _rightLabel = new QLabel("Right Column Widget 1");
    _rightLayout->addWidget(_rightLabel);
    _rightColumn->setFixedWidth(150);  // Set fixed width for right column

    // Add column layouts to the main layout
    _mainLayout->addWidget(_leftColumn);  // Fixed width column
    _mainLayout->addWidget(_middleColumn); // Flexible width column
    _mainLayout->addWidget(_rightColumn);  // Fixed width column

    setLayout(_mainLayout);
}

MainWidget::~MainWidget()
{
    
}