/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routing/Router.hpp"
#include "routing/RouteResolver.hpp"

Router::Router()
    : _routeResolver(NULL), _staticFileHandler(NULL), _deleteHandler(NULL),
      _cgiHandler(NULL), _uploadHandler(NULL), _autoIndexHandler(NULL)
{
}

Router::Router(const Router& other)
{
    *this = other;
}

Router& Router::operator=(const Router& other)
{
    if (this != &other)
    {
        _routeResolver = other._routeResolver;
        _staticFileHandler = other._staticFileHandler;
        _deleteHandler = other._deleteHandler;
        _cgiHandler = other._cgiHandler;
        _uploadHandler = other._uploadHandler;
        _autoIndexHandler = other._autoIndexHandler;
    }
    return *this;
}

Router::~Router()
{
}

HttpResponse* Router::route(HttpRequest* request, ServerConfig* config)
{
    (void)request;
    (void)config;
    return NULL;
}

void Router::init()
{
}

HttpResponse* Router::handleGet(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

HttpResponse* Router::handlePost(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

HttpResponse* Router::handleDelete(HttpRequest* request, LocationConfig* location, ServerConfig* config)
{
    (void)request;
    (void)location;
    (void)config;
    return NULL;
}

HttpResponse* Router::handleRedirect(LocationConfig* location)
{
    (void)location;
    return NULL;
}

HttpResponse* Router::handleMethodNotAllowed()
{
    return NULL;
}

HttpResponse* Router::handleNotFound(ServerConfig* config)
{
    (void)config;
    return NULL;
}

bool Router::isMethodAllowed(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

bool Router::shouldHandleCGI(const std::string& path, LocationConfig* location)
{
    (void)path;
    (void)location;
    return false;
}

bool Router::shouldHandleUpload(HttpRequest* request, LocationConfig* location)
{
    (void)request;
    (void)location;
    return false;
}

bool Router::shouldHandleAutoIndex(const std::string& path, LocationConfig* location)
{
    (void)path;
    (void)location;
    return false;
}
