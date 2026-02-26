/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger
{
public:
    enum Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    static Logger&  getInstance();
    
    void            setLevel(Level level);
    void            setOutputFile(const std::string& path);
    void            enableConsole(bool enable);
    void            enableFile(bool enable);
    
    void            debug(const std::string& message);
    void            info(const std::string& message);
    void            warning(const std::string& message);
    void            error(const std::string& message);
    void            fatal(const std::string& message);
    
    void            log(Level level, const std::string& message);
    void            logAccess(const std::string& clientIP, const std::string& method, 
                              const std::string& uri, int statusCode);

private:
    Logger();
    Logger(const Logger& other);
    Logger& operator=(const Logger& other);
    ~Logger();

    std::string     getLevelString(Level level) const;
    std::string     getTimestamp() const;
    std::string     colorize(Level level, const std::string& message) const;
    void            output(const std::string& message);

    Level           _level;
    bool            _consoleEnabled;
    bool            _fileEnabled;
    std::string     _logFilePath;
    std::ofstream   _logFile;
};

#endif
