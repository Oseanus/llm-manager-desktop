#include "OllamaAPI.h"

OllamaAPI::OllamaAPI(const std::string& apiUri)
    : _apiUri(apiUri)
{
    curl_global_init(CURL_GLOBAL_ALL);
}

OllamaAPI::~OllamaAPI()
{
    curl_global_cleanup();
}

std::vector<std::string> OllamaAPI::ListLLMs()
{
    std::string url = _apiUri + "/api/tags";
    std::string response = PerformGetRequest(url);

    auto modelNames = ParseModelNames(response);
    return modelNames;
}

std::string OllamaAPI::PerformGetRequest(const std::string& apiUri)
{
    std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl(curl_easy_init(), &curl_easy_cleanup);

    if (!curl)
    {
        throw std::runtime_error("Failed to initialize CURL.");
    }

    std::string response;

    curl_easy_setopt(curl.get(), CURLOPT_URL, apiUri.c_str());
    curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl.get(), CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl.get());
    if (res != CURLE_OK)
    {
        throw std::runtime_error("CURL error: " + std::string(curl_easy_strerror(res)));
    }

    return response;
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