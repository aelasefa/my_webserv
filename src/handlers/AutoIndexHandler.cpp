/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndexHandler.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/AutoIndexHandler.hpp"

AutoIndexHandler::AutoIndexHandler()
{
}

AutoIndexHandler::AutoIndexHandler(const AutoIndexHandler& other)
{
    *this = other;
}

AutoIndexHandler& AutoIndexHandler::operator=(const AutoIndexHandler& other)
{
    (void)other;
    return *this;
}

AutoIndexHandler::~AutoIndexHandler()
{
}

HttpResponse* AutoIndexHandler::handle(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

bool AutoIndexHandler::canHandle(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

std::vector<DirectoryEntry> AutoIndexHandler::listDirectory(const std::string& path)
{
    (void)path;
    return std::vector<DirectoryEntry>();
}

std::string AutoIndexHandler::generateHTML(const std::string& uri, const std::vector<DirectoryEntry>& entries)
{
    (void)uri;
    (void)entries;
    return "";
}

std::string AutoIndexHandler::formatSize(size_t size)
{
    (void)size;
    return "";
}

std::string AutoIndexHandler::formatDate(const std::string& date)
{
    (void)date;
    return "";
}

bool AutoIndexHandler::isDirectory(const std::string& path)
{
    (void)path;
    return false;
}
