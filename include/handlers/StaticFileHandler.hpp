/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFileHandler.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATIC_FILE_HANDLER_HPP
#define STATIC_FILE_HANDLER_HPP

#include "handlers/IHandler.hpp"
#include <string>

class StaticFileHandler : public IHandler
{
public:
    StaticFileHandler();
    StaticFileHandler(const StaticFileHandler& other);
    StaticFileHandler& operator=(const StaticFileHandler& other);
    virtual ~StaticFileHandler();

    virtual HttpResponse*   handle(HttpRequest* request, LocationConfig* location, ServerConfig* config);
    virtual bool            canHandle(HttpRequest* request, LocationConfig* location);

private:
    std::string     readFile(const std::string& path);
    std::string     getMimeType(const std::string& path);
    size_t          getFileSize(const std::string& path);
    bool            fileExists(const std::string& path);
};

#endif
