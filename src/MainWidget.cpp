#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent, const std::string url, const int port)
    : QWidget(parent), _api(nullptr)
{
    _api = std::make_unique<OllamaAPI>(url, port);
    std::vector<std::string> models;
    
    try
    {
        models = _api->ListLLMs();
    }
    catch(const std::exception& e)
    {
        close();
    }
    
    _mainLayout = new QHBoxLayout(this);

    CreateLeftPanel(models);
    CreateMiddlePanel();
    CreateRightPanel();

    // Add column layouts to the main layout
    _mainLayout->addWidget(_leftColumn);  // Fixed width column
    _mainLayout->addWidget(_middleColumn); // Flexible width column
    _mainLayout->addWidget(_rightColumn);  // Fixed width column

    setLayout(_mainLayout);

    // Events handler
    CreateEventHandler();
}

MainWidget::~MainWidget()
{
    
}

void MainWidget::CreateLeftPanel(const std::vector<std::string>& models)
{
    _leftColumn = new QWidget();
    _leftLayout = new QVBoxLayout(_leftColumn);
    
    _llmMenu = new QComboBox();

    for(const auto& model : models)
    {
        _llmMenu->addItem(model.c_str());
    }
    
    _leftLayout->addWidget(_llmMenu);

    _selectedLLM = new QLabel(_llmMenu->currentText());
    _leftLayout->addWidget(_selectedLLM);
    
    _leftLabel = new QLabel("Left Column Widget 1");
    _leftLayout->addWidget(_leftLabel);
    _leftColumn->setFixedWidth(150);  // Set fixed width for left column
}

void MainWidget::CreateMiddlePanel()
{
    _middleColumn = new QWidget();
    _middleLayout = new QVBoxLayout(_middleColumn);

    _chatDisplay = new QTextBrowser(this);
    _chatDisplay->setOpenExternalLinks(this);
    _chatDisplay->setReadOnly(this);

    _messageInput = new QLineEdit(this);
    _sendButton = new QPushButton("Send", this);

    _inputLayout = new QHBoxLayout();
    _inputLayout->addWidget(_messageInput);
    _inputLayout->addWidget(_sendButton);

    _middleLayout->addWidget(_chatDisplay);
    _middleLayout->addLayout(_inputLayout);
}

void MainWidget::CreateRightPanel()
{
    _rightColumn = new QWidget();
    _rightLayout = new QVBoxLayout(_rightColumn);

    _rightLabel = new QLabel("Right Column Widget 1");
    _rightLayout->addWidget(_rightLabel);
    _rightColumn->setFixedWidth(150);  // Set fixed width for right column
}

void MainWidget::CreateEventHandler()
{
    connect(_llmMenu, &QComboBox::currentTextChanged, this, [this]()
    {
        this->SetSelectedItem(_llmMenu->currentText());
    });

    connect(_sendButton, &QPushButton::clicked, this, &MainWidget::SendMessage);
    connect(_messageInput, &QLineEdit::returnPressed, this, &MainWidget::SendMessage);
}

void MainWidget::AppendMessage(const QString& sender, const QString& markdownMessage)
{
    QTextDocument doc;
    doc.setMarkdown(markdownMessage);
    QString html = doc.toHtml();

    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");

    _chatDisplay->append(QString("<b>%1 [%2]:</b><br>%3</br>").arg(sender, timestamp, html));
}

void MainWidget::SetSelectedItem(QString item)
{
    _selectedLLM->setText(item);
}

void MainWidget::SendMessage()
{
    QString message = _messageInput->text().trimmed();

    if(message.isEmpty()) return;

    AppendMessage("You", message);
    AppendMessage("Bot", "_This is a mock response._");

    _messageInput->clear();
}