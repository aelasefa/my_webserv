/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AutoIndexHandler.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_INDEX_HANDLER_HPP
#define AUTO_INDEX_HANDLER_HPP

#include "handlers/IHandler.hpp"
#include <string>
#include <vector>

struct DirectoryEntry
{
    std::string name;
    bool        isDirectory;
    size_t      size;
    std::string lastModified;
};

class AutoIndexHandler : public IHandler
{
public:
    AutoIndexHandler();
    AutoIndexHandler(const AutoIndexHandler& other);
    AutoIndexHandler& operator=(const AutoIndexHandler& other);
    virtual ~AutoIndexHandler();

    virtual HttpResponse*           handle(HttpRequest* request, LocationConfig* location, ServerConfig* config);
    virtual bool                    canHandle(HttpRequest* request, LocationConfig* location);

private:
    std::vector<DirectoryEntry>     listDirectory(const std::string& path);
    std::string                     generateHTML(const std::string& uri, const std::vector<DirectoryEntry>& entries);
    std::string                     formatSize(size_t size);
    std::string                     formatDate(const std::string& date);
    bool                            isDirectory(const std::string& path);
};

#endif
