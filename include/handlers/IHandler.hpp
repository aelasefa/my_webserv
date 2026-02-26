/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandler.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IHANDLER_HPP
#define IHANDLER_HPP

class HttpRequest;
class HttpResponse;
class LocationConfig;
class ServerConfig;

class IHandler
{
public:
    virtual ~IHandler() {}
    virtual HttpResponse* handle(HttpRequest* request, LocationConfig* location, ServerConfig* config) = 0;
    virtual bool canHandle(HttpRequest* request, LocationConfig* location) = 0;
};

#endif
