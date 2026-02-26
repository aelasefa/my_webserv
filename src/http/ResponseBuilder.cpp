/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseBuilder.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/ResponseBuilder.hpp"
#include "http/HttpResponse.hpp"
#include "http/HttpRequest.hpp"

ResponseBuilder::ResponseBuilder()
{
}

ResponseBuilder::ResponseBuilder(const ResponseBuilder& other)
{
    *this = other;
}

ResponseBuilder& ResponseBuilder::operator=(const ResponseBuilder& other)
{
    (void)other;
    return *this;
}

ResponseBuilder::~ResponseBuilder()
{
}

HttpResponse* ResponseBuilder::buildResponse(HttpRequest* request, ServerConfig* config)
{
    (void)request;
    (void)config;
    return NULL;
}

HttpResponse* ResponseBuilder::buildErrorResponse(int statusCode, ServerConfig* config)
{
    (void)statusCode;
    (void)config;
    return NULL;
}

HttpResponse* ResponseBuilder::buildRedirectResponse(const std::string& location, int code)
{
    (void)location;
    (void)code;
    return NULL;
}

HttpResponse* ResponseBuilder::buildFileResponse(const std::string& filePath, const std::string& contentType)
{
    (void)filePath;
    (void)contentType;
    return NULL;
}

HttpResponse* ResponseBuilder::buildDirectoryListing(const std::string& path, const std::string& uri)
{
    (void)path;
    (void)uri;
    return NULL;
}

void ResponseBuilder::addDefaultHeaders(HttpResponse* response)
{
    (void)response;
}

void ResponseBuilder::addDateHeader(HttpResponse* response)
{
    (void)response;
}

void ResponseBuilder::addServerHeader(HttpResponse* response)
{
    (void)response;
}

void ResponseBuilder::addConnectionHeader(HttpResponse* response, bool keepAlive)
{
    (void)response;
    (void)keepAlive;
}

std::string ResponseBuilder::getDefaultErrorPage(int statusCode) const
{
    (void)statusCode;
    return "";
}

std::string ResponseBuilder::getCurrentDateString() const
{
    return "";
}
