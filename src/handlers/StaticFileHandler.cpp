/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFileHandler.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/StaticFileHandler.hpp"

StaticFileHandler::StaticFileHandler()
{
}

StaticFileHandler::StaticFileHandler(const StaticFileHandler& other)
{
    *this = other;
}

StaticFileHandler& StaticFileHandler::operator=(const StaticFileHandler& other)
{
    (void)other;
    return *this;
}

StaticFileHandler::~StaticFileHandler()
{
}

HttpResponse* StaticFileHandler::handle(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

bool StaticFileHandler::canHandle(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

std::string StaticFileHandler::readFile(const std::string& path)
{
    (void)path;
    return "";
}

std::string StaticFileHandler::getMimeType(const std::string& path)
{
    (void)path;
    return "";
}

size_t StaticFileHandler::getFileSize(const std::string& path)
{
    (void)path;
    return 0;
}

bool StaticFileHandler::fileExists(const std::string& path)
{
    (void)path;
    return false;
}
