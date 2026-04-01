#include "HttpResponse.hpp"
#include <sstream>

HttpResponse::HttpResponse() : _version("HTTP/1.1"), _status("200 OK")
{
}

HttpResponse::~HttpResponse()
{
}

void HttpResponse::setVersion(const std::string& version)
{
    _version = version;
}

void HttpResponse::setStatus(const std::string& status)
{
    _status = status;
}

void HttpResponse::addHeader(const std::string& key, const std::string& value)
{
    _headers[key] = value;
}

void HttpResponse::setBody(const std::string& body)
{
    _body = body;
}

const std::string& HttpResponse::getVersion() const
{
    return _version;
}

const std::string& HttpResponse::getStatus() const
{
    return _status;
}

const std::map<std::string, std::string>& HttpResponse::getHeaders() const
{
    return _headers;
}

const std::string& HttpResponse::getBody() const
{
    return _body;
}

std::string HttpResponse::buildResponse() const
{
    std::ostringstream response;
    
    // Status line: HTTP/1.1 200 OK\r\n
    response << _version << " " << _status << "\r\n";
    
    // Headers: key: value\r\n
    for (std::map<std::string, std::string>::const_iterator it = _headers.begin(); it != _headers.end(); ++it)
    {
        response << it->first << ": " << it->second << "\r\n";
    }
    
    // Empty line separating headers and body
    response << "\r\n";
    
    // Body
    response << _body;
    
    return response.str();
}

std::string HttpResponse::buildRawResponse() const
{
    return buildResponse();
}
