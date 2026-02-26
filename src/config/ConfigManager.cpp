/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/ConfigManager.hpp"
#include "config/ServerConfig.hpp"

ConfigManager::ConfigManager()
{
}

ConfigManager::ConfigManager(const ConfigManager& other)
{
    *this = other;
}

ConfigManager& ConfigManager::operator=(const ConfigManager& other)
{
    if (this != &other)
    {
        _serverConfigs = other._serverConfigs;
        _configPath = other._configPath;
    }
    return *this;
}

ConfigManager::~ConfigManager()
{
}

bool ConfigManager::initHardcoded()
{
    return false;
}

bool ConfigManager::loadFromFile(const std::string& path)
{
    (void)path;
    return false;
}

std::vector<ServerConfig*>& ConfigManager::getServerConfigs()
{
    return _serverConfigs;
}

const std::vector<ServerConfig*>& ConfigManager::getServerConfigs() const
{
    return _serverConfigs;
}

ServerConfig* ConfigManager::getServerConfig(size_t index)
{
    (void)index;
    return NULL;
}

size_t ConfigManager::getServerCount() const
{
    return _serverConfigs.size();
}

void ConfigManager::addServerConfig(ServerConfig* config)
{
    (void)config;
}

void ConfigManager::clear()
{
}

bool ConfigManager::validate() const
{
    return false;
}
