/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGIHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HANDLER_HPP
#define CGI_HANDLER_HPP

#include "handlers/IHandler.hpp"
#include <string>
#include <map>
#include <vector>

class CGIHandler : public IHandler
{
public:
    CGIHandler();
    CGIHandler(const CGIHandler& other);
    CGIHandler& operator=(const CGIHandler& other);
    virtual ~CGIHandler();

    virtual HttpResponse*   handle(HttpRequest* request, LocationConfig* location, ServerConfig* config);
    virtual bool            canHandle(HttpRequest* request, LocationConfig* location);

private:
    char**                          buildEnvp(HttpRequest* request, LocationConfig* location, const std::string& scriptPath);
    void                            freeEnvp(char** envp);
    std::string                     executeCGI(const std::string& scriptPath, const std::string& interpreter, HttpRequest* request, char** envp);
    HttpResponse*                   parseCGIOutput(const std::string& output);
    std::map<std::string, std::string> getEnvironmentVariables(HttpRequest* request, LocationConfig* location, const std::string& scriptPath);
    
    bool                            isCGIExtension(const std::string& path, LocationConfig* location);
    std::string                     getScriptPath(const std::string& uri, LocationConfig* location);
    std::string                     getPathInfo(const std::string& uri, const std::string& scriptPath);
    
    int                             _timeout;
    static const int                BUFFER_SIZE = 4096;
};

#endif
