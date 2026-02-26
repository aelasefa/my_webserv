/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/Logger.hpp"

Logger::Logger() : _level(INFO), _consoleEnabled(true), _fileEnabled(false)
{
}

Logger::Logger(const Logger& other)
{
    *this = other;
}

Logger& Logger::operator=(const Logger& other)
{
    if (this != &other)
    {
        _level = other._level;
        _consoleEnabled = other._consoleEnabled;
        _fileEnabled = other._fileEnabled;
        _logFilePath = other._logFilePath;
    }
    return *this;
}

Logger::~Logger()
{
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::setLevel(Level level)
{
    (void)level;
}

void Logger::setOutputFile(const std::string& path)
{
    (void)path;
}

void Logger::enableConsole(bool enable)
{
    (void)enable;
}

void Logger::enableFile(bool enable)
{
    (void)enable;
}

void Logger::debug(const std::string& message)
{
    (void)message;
}

void Logger::info(const std::string& message)
{
    (void)message;
}

void Logger::warning(const std::string& message)
{
    (void)message;
}

void Logger::error(const std::string& message)
{
    (void)message;
}

void Logger::fatal(const std::string& message)
{
    (void)message;
}

void Logger::log(Level level, const std::string& message)
{
    (void)level;
    (void)message;
}

void Logger::logAccess(const std::string& clientIP, const std::string& method, 
                       const std::string& uri, int statusCode)
{
    (void)clientIP;
    (void)method;
    (void)uri;
    (void)statusCode;
}

std::string Logger::getLevelString(Level level) const
{
    (void)level;
    return "";
}

std::string Logger::getTimestamp() const
{
    return "";
}

std::string Logger::colorize(Level level, const std::string& message) const
{
    (void)level;
    (void)message;
    return "";
}

void Logger::output(const std::string& message)
{
    (void)message;
}
