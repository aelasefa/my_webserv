/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeleteHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/DeleteHandler.hpp"

DeleteHandler::DeleteHandler()
{
}

DeleteHandler::DeleteHandler(const DeleteHandler& other)
{
    *this = other;
}

DeleteHandler& DeleteHandler::operator=(const DeleteHandler& other)
{
    (void)other;
    return *this;
}

DeleteHandler::~DeleteHandler()
{
}

HttpResponse* DeleteHandler::handle(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

bool DeleteHandler::canHandle(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

bool DeleteHandler::deleteFile(const std::string& path)
{
    (void)path;
    return false;
}

bool DeleteHandler::fileExists(const std::string& path)
{
    (void)path;
    return false;
}

bool DeleteHandler::isWritable(const std::string& path)
{
    (void)path;
    return false;
}
