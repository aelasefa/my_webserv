/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/ServerConfig.hpp"
#include "config/LocationConfig.hpp"

ServerConfig::ServerConfig()
    : _port(80), _clientMaxBodySize(1048576)
{
}

ServerConfig::ServerConfig(const ServerConfig& other)
{
    *this = other;
}

ServerConfig& ServerConfig::operator=(const ServerConfig& other)
{
    if (this != &other)
    {
        _host = other._host;
        _port = other._port;
        _serverNames = other._serverNames;
        _root = other._root;
        _index = other._index;
        _clientMaxBodySize = other._clientMaxBodySize;
        _errorPages = other._errorPages;
        _locations = other._locations;
    }
    return *this;
}

ServerConfig::~ServerConfig()
{
}

std::string ServerConfig::getHost() const
{
    return _host;
}

int ServerConfig::getPort() const
{
    return _port;
}

std::vector<std::string> ServerConfig::getServerNames() const
{
    return _serverNames;
}

std::string ServerConfig::getRoot() const
{
    return _root;
}

std::string ServerConfig::getIndex() const
{
    return _index;
}

size_t ServerConfig::getClientMaxBodySize() const
{
    return _clientMaxBodySize;
}

std::map<int, std::string> ServerConfig::getErrorPages() const
{
    return _errorPages;
}

std::vector<LocationConfig*>& ServerConfig::getLocations()
{
    return _locations;
}

const std::vector<LocationConfig*>& ServerConfig::getLocations() const
{
    return _locations;
}

void ServerConfig::setHost(const std::string& host)
{
    (void)host;
}

void ServerConfig::setPort(int port)
{
    (void)port;
}

void ServerConfig::addServerName(const std::string& name)
{
    (void)name;
}

void ServerConfig::setServerNames(const std::vector<std::string>& names)
{
    (void)names;
}

void ServerConfig::setRoot(const std::string& root)
{
    (void)root;
}

void ServerConfig::setIndex(const std::string& index)
{
    (void)index;
}

void ServerConfig::setClientMaxBodySize(size_t size)
{
    (void)size;
}

void ServerConfig::addErrorPage(int code, const std::string& path)
{
    (void)code;
    (void)path;
}

void ServerConfig::addLocation(LocationConfig* location)
{
    (void)location;
}

bool ServerConfig::matchServerName(const std::string& name) const
{
    (void)name;
    return false;
}

LocationConfig* ServerConfig::findLocation(const std::string& uri) const
{
    (void)uri;
    return NULL;
}

std::string ServerConfig::getErrorPage(int code) const
{
    (void)code;
    return "";
}
