#include "HttpRequest.hpp"
#include <sstream>
#include <stdexcept>

namespace
{
size_t parseContentLengthValue(const std::string& value)
{
    if (value.empty())
        return 0;

    std::istringstream iss(value);
    size_t length = 0;
    char extra = 0;
    if (!(iss >> length) || (iss >> extra))
        return 0;
    return length;
}
}

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

bool HttpRequest::hasBody() const
{
    return !_body.empty();
}

size_t HttpRequest::getContentLength() const
{
    std::map<std::string, std::string>::const_iterator it = _headers.find("Content-Length");
    if (it == _headers.end())
        return 0;
    return parseContentLengthValue(it->second);
}

void HttpRequest::parse(const std::string& rawRequest)
{
    _method.clear();
    _uri.clear();
    _version.clear();
    _headers.clear();
    _body.clear();

    const size_t headerEnd = rawRequest.find("\r\n\r\n");
    if (headerEnd == std::string::npos)
        throw std::runtime_error("Incomplete HTTP headers");

    std::istringstream stream(rawRequest.substr(0, headerEnd));
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

    const size_t bodyStart = headerEnd + 4;
    const size_t contentLength = getContentLength();

    if (contentLength > 0)
    {
        if (rawRequest.size() < bodyStart + contentLength)
            throw std::runtime_error("Incomplete HTTP body");
        _body = rawRequest.substr(bodyStart, contentLength);
    }
    else if (bodyStart < rawRequest.size())
    {
        _body = rawRequest.substr(bodyStart);
    }
}

bool HttpRequest::isComplete() const
{
    return !_method.empty() && !_uri.empty() && !_version.empty() && _body.size() >= getContentLength();
}