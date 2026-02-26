/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeleteHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELETE_HANDLER_HPP
#define DELETE_HANDLER_HPP

#include "handlers/IHandler.hpp"
#include <string>

class DeleteHandler : public IHandler
{
public:
    DeleteHandler();
    DeleteHandler(const DeleteHandler& other);
    DeleteHandler& operator=(const DeleteHandler& other);
    virtual ~DeleteHandler();

    virtual HttpResponse*   handle(HttpRequest* request, LocationConfig* location, ServerConfig* config);
    virtual bool            canHandle(HttpRequest* request, LocationConfig* location);

private:
    bool    deleteFile(const std::string& path);
    bool    fileExists(const std::string& path);
    bool    isWritable(const std::string& path);
};

#endif
