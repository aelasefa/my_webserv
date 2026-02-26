/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGIHandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers/CGIHandler.hpp"

CGIHandler::CGIHandler() : _timeout(30)
{
}

CGIHandler::CGIHandler(const CGIHandler& other)
{
    *this = other;
}

CGIHandler& CGIHandler::operator=(const CGIHandler& other)
{
    if (this != &other)
    {
        _timeout = other._timeout;
    }
    return *this;
}

CGIHandler::~CGIHandler()
{
}

HttpResponse* CGIHandler::handle(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

bool CGIHandler::canHandle(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

char** CGIHandler::buildEnvp(HttpRequest* request, LocationConfig* location, const std::string& scriptPath)
{
    (void)request;
    (void)location;
    (void)scriptPath;
    return NULL;
}

void CGIHandler::freeEnvp(char** envp)
{
    (void)envp;
}

std::string CGIHandler::executeCGI(const std::string& scriptPath, const std::string& interpreter, HttpRequest* request, char** envp)
{
    (void)scriptPath;
    (void)interpreter;
    (void)request;
    (void)envp;
    return "";
}

HttpResponse* CGIHandler::parseCGIOutput(const std::string& output)
{
    (void)output;
    return NULL;
}

std::map<std::string, std::string> CGIHandler::getEnvironmentVariables(HttpRequest* request, LocationConfig* location, const std::string& scriptPath)
{
    (void)request;
    (void)location;
    (void)scriptPath;
    return std::map<std::string, std::string>();
}

bool CGIHandler::isCGIExtension(const std::string& path, LocationConfig* location)
{
    (void)path;
    (void)location;
    return false;
}

std::string CGIHandler::getScriptPath(const std::string& uri, LocationConfig* location)
{
    (void)uri;
    (void)location;
    return "";
}

std::string CGIHandler::getPathInfo(const std::string& uri, const std::string& scriptPath)
{
    (void)uri;
    (void)scriptPath;
    return "";
}
