/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConfig.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/LocationConfig.hpp"

LocationConfig::LocationConfig()
    : _autoIndex(false), _clientMaxBodySize(1048576), 
      _redirectCode(0), _cgiEnabled(false)
{
}

LocationConfig::LocationConfig(const std::string& path)
    : _path(path), _autoIndex(false), _clientMaxBodySize(1048576),
      _redirectCode(0), _cgiEnabled(false)
{
}

LocationConfig::LocationConfig(const LocationConfig& other)
{
    *this = other;
}

LocationConfig& LocationConfig::operator=(const LocationConfig& other)
{
    if (this != &other)
    {
        _path = other._path;
        _root = other._root;
        _index = other._index;
        _allowedMethods = other._allowedMethods;
        _autoIndex = other._autoIndex;
        _uploadDir = other._uploadDir;
        _clientMaxBodySize = other._clientMaxBodySize;
        _redirect = other._redirect;
        _redirectCode = other._redirectCode;
        _cgiExtension = other._cgiExtension;
        _cgiPath = other._cgiPath;
        _cgiEnabled = other._cgiEnabled;
        _errorPages = other._errorPages;
        _alias = other._alias;
    }
    return *this;
}

LocationConfig::~LocationConfig()
{
}

std::string LocationConfig::getPath() const
{
    return _path;
}

std::string LocationConfig::getRoot() const
{
    return _root;
}

std::string LocationConfig::getIndex() const
{
    return _index;
}

std::vector<std::string> LocationConfig::getAllowedMethods() const
{
    return _allowedMethods;
}

bool LocationConfig::isAutoIndexEnabled() const
{
    return _autoIndex;
}

std::string LocationConfig::getUploadDir() const
{
    return _uploadDir;
}

size_t LocationConfig::getClientMaxBodySize() const
{
    return _clientMaxBodySize;
}

std::string LocationConfig::getRedirect() const
{
    return _redirect;
}

int LocationConfig::getRedirectCode() const
{
    return _redirectCode;
}

std::string LocationConfig::getCgiExtension() const
{
    return _cgiExtension;
}

std::string LocationConfig::getCgiPath() const
{
    return _cgiPath;
}

bool LocationConfig::isCgiEnabled() const
{
    return _cgiEnabled;
}

std::map<int, std::string> LocationConfig::getErrorPages() const
{
    return _errorPages;
}

std::string LocationConfig::getAlias() const
{
    return _alias;
}

void LocationConfig::setPath(const std::string& path)
{
    (void)path;
}

void LocationConfig::setRoot(const std::string& root)
{
    (void)root;
}

void LocationConfig::setIndex(const std::string& index)
{
    (void)index;
}

void LocationConfig::setAllowedMethods(const std::vector<std::string>& methods)
{
    (void)methods;
}

void LocationConfig::addAllowedMethod(const std::string& method)
{
    (void)method;
}

void LocationConfig::setAutoIndex(bool enabled)
{
    (void)enabled;
}

void LocationConfig::setUploadDir(const std::string& dir)
{
    (void)dir;
}

void LocationConfig::setClientMaxBodySize(size_t size)
{
    (void)size;
}

void LocationConfig::setRedirect(const std::string& redirect, int code)
{
    (void)redirect;
    (void)code;
}

void LocationConfig::setCgiExtension(const std::string& extension)
{
    (void)extension;
}

void LocationConfig::setCgiPath(const std::string& path)
{
    (void)path;
}

void LocationConfig::setCgiEnabled(bool enabled)
{
    (void)enabled;
}

void LocationConfig::addErrorPage(int code, const std::string& path)
{
    (void)code;
    (void)path;
}

void LocationConfig::setAlias(const std::string& alias)
{
    (void)alias;
}

bool LocationConfig::isMethodAllowed(const std::string& method) const
{
    (void)method;
    return false;
}

bool LocationConfig::hasRedirect() const
{
    return false;
}
