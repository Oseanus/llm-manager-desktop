#ifndef OLLAMA_API_H
#define OLLAMA_API_H

#include "LlmManager.h"

class OllamaAPI
{
private: // Fields
    std::string _apiUri;

public: // Methods
    OllamaAPI() = default;
    OllamaAPI(const std::string& apiUri);
    ~OllamaAPI();

    std::vector<std::string> ListLLMs();

private: // Methods
    std::string PerformGetRequest(const std::string& apiUri);
    std::vector<std::string> ParseModelNames(const std::string& jsonStr);
    static size_t WriteCallback(char *contents, size_t size, size_t nmemb, std::unique_ptr<std::string> userp);
};

#endif