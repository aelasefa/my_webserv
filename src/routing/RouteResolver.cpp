/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RouteResolver.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routing/RouteResolver.hpp"

RouteResolver::RouteResolver()
{
}

RouteResolver::RouteResolver(const RouteResolver& other)
{
    *this = other;
}

RouteResolver& RouteResolver::operator=(const RouteResolver& other)
{
    (void)other;
    return *this;
}

RouteResolver::~RouteResolver()
{
}

LocationConfig* RouteResolver::resolve(const std::string& uri, ServerConfig* config)
{
    (void)uri;
    (void)config;
    return NULL;
}

std::string RouteResolver::resolvePath(const std::string& uri, LocationConfig* location)
{
    (void)uri;
    (void)location;
    return "";
}

std::string RouteResolver::resolveIndexFile(const std::string& dirPath, LocationConfig* location)
{
    (void)dirPath;
    (void)location;
    return "";
}

bool RouteResolver::isDirectory(const std::string& path) const
{
    (void)path;
    return false;
}

bool RouteResolver::isFile(const std::string& path) const
{
    (void)path;
    return false;
}

bool RouteResolver::fileExists(const std::string& path) const
{
    (void)path;
    return false;
}

bool RouteResolver::isReadable(const std::string& path) const
{
    (void)path;
    return false;
}

bool RouteResolver::isWritable(const std::string& path) const
{
    (void)path;
    return false;
}

LocationConfig* RouteResolver::findBestMatch(const std::string& uri, ServerConfig* config)
{
    (void)uri;
    (void)config;
    return NULL;
}

std::string RouteResolver::normalizePath(const std::string& path) const
{
    (void)path;
    return "";
}

std::string RouteResolver::joinPaths(const std::string& base, const std::string& path) const
{
    (void)base;
    (void)path;
    return "";
}

bool RouteResolver::matchLocation(const std::string& uri, const std::string& locationPath) const
{
    (void)uri;
    (void)locationPath;
    return false;
}
