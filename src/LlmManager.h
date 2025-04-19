#ifndef LLM_MANAGER_H
#define LLM_MANAGER_H

// Standard libs
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>

// Qt related libs
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QPointer>
#include <QString>
#include <QLineEdit>
#include <QTextBrowser>
#include <QTextDocument>
#include <QDateTime>

// Third party libs
#include "httplib.h"

// Custom code
#include "OllamaAPI.h"
#include "MainWidget.h"

using json = nlohmann::json;

#endif