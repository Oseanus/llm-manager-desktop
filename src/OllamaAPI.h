#ifndef OLLAMA_API_H
#define OLLAMA_API_H

#include "LlmManager.h"

using Client = httplib::Client;
using Error = httplib::Error;

class OllamaAPI
{
private: // Fields
    const std::string _url;
    const int _port;
    std::unique_ptr<Client> _client;

public: // Methods
    OllamaAPI() = default;
    OllamaAPI(const std::string url, const int port);
    ~OllamaAPI();

    std::vector<std::string> ListLLMs();
    std::string SendMessage(const std::string& prompt, const std::string& model);

private: // Methods
    std::string PerformGetRequest(const std::string&& endPoint);
    std::vector<std::string> ParseModelNames(const std::string& jsonStr);
    static size_t WriteCallback(char *contents, size_t size, size_t nmemb, std::unique_ptr<std::string> userp);
};

#endif