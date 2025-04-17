#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include "LlmManager.h"

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

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void SetSelectedItem(QString item);
};

#endif