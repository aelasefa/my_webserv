/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/HttpRequest.hpp"

HttpRequest::HttpRequest()
    : _method(UNKNOWN), _httpVersion("HTTP/1.1"), _parseState(PARSE_REQUEST_LINE)
{
}

HttpRequest::HttpRequest(const HttpRequest& other)
{
    *this = other;
}

HttpRequest& HttpRequest::operator=(const HttpRequest& other)
{
    if (this != &other)
    {
        _method = other._method;
        _uri = other._uri;
        _path = other._path;
        _queryString = other._queryString;
        _httpVersion = other._httpVersion;
        _headers = other._headers;
        _body = other._body;
        _parseState = other._parseState;
        _errorMessage = other._errorMessage;
    }
    return *this;
}

HttpRequest::~HttpRequest()
{
}

HttpRequest::Method HttpRequest::getMethod() const
{
    return _method;
}

std::string HttpRequest::getMethodString() const
{
    return "";
}

std::string HttpRequest::getUri() const
{
    return _uri;
}

std::string HttpRequest::getPath() const
{
    return _path;
}

std::string HttpRequest::getQueryString() const
{
    return _queryString;
}

std::string HttpRequest::getHttpVersion() const
{
    return _httpVersion;
}

std::string HttpRequest::getHeader(const std::string& name) const
{
    (void)name;
    return "";
}

std::map<std::string, std::string> HttpRequest::getHeaders() const
{
    return _headers;
}

std::string HttpRequest::getBody() const
{
    return _body;
}

size_t HttpRequest::getContentLength() const
{
    return 0;
}

std::string HttpRequest::getHost() const
{
    return "";
}

HttpRequest::ParseState HttpRequest::getParseState() const
{
    return _parseState;
}

bool HttpRequest::isComplete() const
{
    return false;
}

bool HttpRequest::hasError() const
{
    return false;
}

std::string HttpRequest::getErrorMessage() const
{
    return _errorMessage;
}

void HttpRequest::setMethod(Method method)
{
    (void)method;
}

void HttpRequest::setMethod(const std::string& method)
{
    (void)method;
}

void HttpRequest::setUri(const std::string& uri)
{
    (void)uri;
}

void HttpRequest::setPath(const std::string& path)
{
    (void)path;
}

void HttpRequest::setQueryString(const std::string& query)
{
    (void)query;
}

void HttpRequest::setHttpVersion(const std::string& version)
{
    (void)version;
}

void HttpRequest::setHeader(const std::string& name, const std::string& value)
{
    (void)name;
    (void)value;
}

void HttpRequest::setBody(const std::string& body)
{
    (void)body;
}

void HttpRequest::appendBody(const std::string& data)
{
    (void)data;
}

void HttpRequest::setParseState(ParseState state)
{
    (void)state;
}

void HttpRequest::setError(const std::string& message)
{
    (void)message;
}

void HttpRequest::clear()
{
}

bool HttpRequest::isChunked() const
{
    return false;
}

bool HttpRequest::keepAlive() const
{
    return false;
}
