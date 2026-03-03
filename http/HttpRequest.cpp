#include "HttpRequest.hpp"
#include <sstream>

HttpRequest::HttpRequest()
{
}

HttpRequest::~HttpRequest()
{
}

void HttpRequest::setMethod(const std::string& method)
{
    _method = method;
}

void HttpRequest::setUri(const std::string& uri)
{
    _uri = uri;
}

void HttpRequest::setVersion(const std::string& version)
{
    _version = version;
}

void HttpRequest::addHeader(const std::string& key, const std::string& value)
{
    _headers[key] = value;
}

void HttpRequest::setBody(const std::string& body)
{
    _body = body;
}

const std::string& HttpRequest::getMethod() const
{
    return _method;
}

const std::string& HttpRequest::getUri() const
{
    return _uri;
}

const std::string& HttpRequest::getVersion() const
{
    return _version;
}

const std::map<std::string, std::string>& HttpRequest::getHeaders() const
{
    return _headers;
}

const std::string& HttpRequest::getBody() const
{
    return _body;
}

#include <sstream>
#include <stdexcept>

void HttpRequest::parse(const std::string& rawRequest)
{
    _method.clear();
    _uri.clear();
    _version.clear();
    _headers.clear();
    _body.clear();

    std::istringstream stream(rawRequest);
    std::string line;

    if (!std::getline(stream, line))
        throw std::runtime_error("Empty HTTP request");

    if (!line.empty() && line[line.size() - 1] == '\r')
        line.erase(line.size() - 1);

    std::istringstream requestLine(line);
    if (!(requestLine >> _method >> _uri >> _version))
        throw std::runtime_error("Invalid HTTP request line");

    if (_method.empty() || _uri.empty() || _version.empty())
        throw std::runtime_error("Malformed HTTP request line");

    while (std::getline(stream, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        if (line.empty())
            break;

        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos)
            continue; 
        std::string key = line.substr(0, colonPos);
        std::string value = line.substr(colonPos + 1);

        size_t start = value.find_first_not_of(" \t");
        if (start != std::string::npos)
            value = value.substr(start);
        else
            value.clear();

        _headers[key] = value;
    }

    std::ostringstream bodyStream;
    bodyStream << stream.rdbuf();
    _body = bodyStream.str();
    
}