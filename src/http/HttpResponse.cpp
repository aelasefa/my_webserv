/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/HttpResponse.hpp"

HttpResponse::HttpResponse()
    : _statusCode(200), _statusMessage("OK"), _httpVersion("HTTP/1.1"), _isReady(false)
{
}

HttpResponse::HttpResponse(const HttpResponse& other)
{
    *this = other;
}

HttpResponse& HttpResponse::operator=(const HttpResponse& other)
{
    if (this != &other)
    {
        _statusCode = other._statusCode;
        _statusMessage = other._statusMessage;
        _httpVersion = other._httpVersion;
        _headers = other._headers;
        _body = other._body;
        _isReady = other._isReady;
    }
    return *this;
}

HttpResponse::~HttpResponse()
{
}

int HttpResponse::getStatusCode() const
{
    return _statusCode;
}

std::string HttpResponse::getStatusMessage() const
{
    return _statusMessage;
}

std::string HttpResponse::getHttpVersion() const
{
    return _httpVersion;
}

std::string HttpResponse::getHeader(const std::string& name) const
{
    (void)name;
    return "";
}

std::map<std::string, std::string> HttpResponse::getHeaders() const
{
    return _headers;
}

std::string HttpResponse::getBody() const
{
    return _body;
}

size_t HttpResponse::getContentLength() const
{
    return _body.size();
}

bool HttpResponse::isReady() const
{
    return _isReady;
}

void HttpResponse::setStatusCode(int code)
{
    (void)code;
}

void HttpResponse::setStatusMessage(const std::string& message)
{
    (void)message;
}

void HttpResponse::setHttpVersion(const std::string& version)
{
    (void)version;
}

void HttpResponse::setHeader(const std::string& name, const std::string& value)
{
    (void)name;
    (void)value;
}

void HttpResponse::setBody(const std::string& body)
{
    (void)body;
}

void HttpResponse::appendBody(const std::string& data)
{
    (void)data;
}

void HttpResponse::setContentType(const std::string& type)
{
    (void)type;
}

void HttpResponse::setContentLength(size_t length)
{
    (void)length;
}

void HttpResponse::setReady(bool ready)
{
    (void)ready;
}

void HttpResponse::clear()
{
}

std::string HttpResponse::build() const
{
    return "";
}

std::string HttpResponse::buildHeaders() const
{
    return "";
}

void HttpResponse::setRedirect(const std::string& location, int code)
{
    (void)location;
    (void)code;
}

void HttpResponse::setError(int code, const std::string& body)
{
    (void)code;
    (void)body;
}
