/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestParser.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/RequestParser.hpp"
#include "http/HttpRequest.hpp"

RequestParser::RequestParser()
    : _bytesConsumed(0), _contentLength(0), _isChunked(false)
{
}

RequestParser::RequestParser(const RequestParser& other)
{
    *this = other;
}

RequestParser& RequestParser::operator=(const RequestParser& other)
{
    if (this != &other)
    {
        _buffer = other._buffer;
        _errorMessage = other._errorMessage;
        _bytesConsumed = other._bytesConsumed;
        _contentLength = other._contentLength;
        _isChunked = other._isChunked;
    }
    return *this;
}

RequestParser::~RequestParser()
{
}

RequestParser::ParseResult RequestParser::parse(const std::string& data, HttpRequest& request)
{
    (void)data;
    (void)request;
    return PARSE_INCOMPLETE;
}

void RequestParser::reset()
{
}

std::string RequestParser::getErrorMessage() const
{
    return _errorMessage;
}

size_t RequestParser::getBytesConsumed() const
{
    return _bytesConsumed;
}

RequestParser::ParseResult RequestParser::parseRequestLine(const std::string& line, HttpRequest& request)
{
    (void)line;
    (void)request;
    return PARSE_INCOMPLETE;
}

RequestParser::ParseResult RequestParser::parseHeaders(const std::string& data, HttpRequest& request)
{
    (void)data;
    (void)request;
    return PARSE_INCOMPLETE;
}

RequestParser::ParseResult RequestParser::parseBody(const std::string& data, HttpRequest& request)
{
    (void)data;
    (void)request;
    return PARSE_INCOMPLETE;
}

RequestParser::ParseResult RequestParser::parseChunkedBody(const std::string& data, HttpRequest& request)
{
    (void)data;
    (void)request;
    return PARSE_INCOMPLETE;
}

std::string RequestParser::trim(const std::string& str) const
{
    (void)str;
    return "";
}

std::string RequestParser::toLower(const std::string& str) const
{
    (void)str;
    return "";
}
