#include "OllamaAPI.h"

OllamaAPI::OllamaAPI(const std::string url, const int port)
    : _url(url), _port(port)
{
    _client = std::make_unique<Client>(_url, _port);
}

OllamaAPI::~OllamaAPI()
{
    
}

std::vector<std::string> OllamaAPI::ListLLMs()
{
    std::string response = PerformGetRequest("/api/tags");

    auto modelNames = ParseModelNames(response);
    return modelNames;
}

std::string OllamaAPI::PerformGetRequest(const std::string&& endPoint)
{
    auto result = _client->Get(endPoint);
    
    if(result.error() != Error::Success)
    {
        throw std::runtime_error("Failed to retrieve models.");
    }

    auto response = result.value();
    
    if(response.status != 200)
    {
        throw std::runtime_error("Failed to connect to OLLAMA API");
    }

    return response.body;
}

std::vector<std::string> OllamaAPI::ParseModelNames(const std::string& jsonStr)
{
    std::vector<std::string> models;
    auto parsed = json::parse(jsonStr);

    if (parsed.contains("models") && parsed["models"].is_array())
    {
        for (const auto& model : parsed["models"])
        {
            if (model.contains("name"))
            {
                models.push_back(model["name"].get<std::string>());
            }
        }
    }

    return models;
}

size_t OllamaAPI::WriteCallback(char *contents, size_t size, size_t nmemb, std::unique_ptr<std::string> userp)
{
    size_t totalSize = size * nmemb;
    userp->append(contents, totalSize);
    return totalSize;
}