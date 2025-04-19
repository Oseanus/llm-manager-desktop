#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include "LlmManager.h"

class OllamaAPI;

class MainWidget : public QWidget
{
private:
    QPointer<QHBoxLayout> _mainLayout;
    QPointer<QWidget> _leftColumn;
    QPointer<QVBoxLayout> _leftLayout;
    QPointer<QComboBox> _llmMenu;
    QPointer<QLabel> _selectedLLM;
    QPointer<QLabel> _leftLabel;
    QPointer<QWidget> _middleColumn;
    QPointer<QVBoxLayout> _middleLayout;
    QPointer<QLabel> _middleLabel;
    QPointer<QWidget> _rightColumn;
    QPointer<QVBoxLayout> _rightLayout;
    QPointer<QLabel> _rightLabel;
    QPointer<QTextBrowser> _chatDisplay;
    QPointer<QLineEdit> _messageInput;
    QPointer<QPushButton> _sendButton;
    QPointer<QHBoxLayout> _inputLayout;

    std::unique_ptr<OllamaAPI> _api;

public: // Methods
    MainWidget(QWidget *parent = nullptr, const std::string url = "127.0.0.1", const int port = 11434);
    ~MainWidget();

private slots:
    void SendMessage();
    
private: // Methods
    void CreateLeftPanel(const std::vector<std::string>& models);
    void CreateMiddlePanel();
    void CreateRightPanel();
    void CreateEventHandler();
    void AppendMessage(const QString& sender, const QString& markdownMessage);
    void SetSelectedItem(QString item);

};

#endif