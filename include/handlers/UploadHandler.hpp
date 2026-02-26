/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UploadHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPLOAD_HANDLER_HPP
#define UPLOAD_HANDLER_HPP

#include "handlers/IHandler.hpp"
#include <string>
#include <vector>

struct UploadedFile
{
    std::string filename;
    std::string contentType;
    std::string data;
};

class UploadHandler : public IHandler
{
public:
    UploadHandler();
    UploadHandler(const UploadHandler& other);
    UploadHandler& operator=(const UploadHandler& other);
    virtual ~UploadHandler();

    virtual HttpResponse*           handle(HttpRequest* request, LocationConfig* location, ServerConfig* config);
    virtual bool                    canHandle(HttpRequest* request, LocationConfig* location);

private:
    std::vector<UploadedFile>       parseMultipartData(const std::string& body, const std::string& boundary);
    std::string                     extractBoundary(const std::string& contentType);
    bool                            saveFile(const UploadedFile& file, const std::string& uploadDir);
    bool                            isValidFilename(const std::string& filename);
    std::string                     sanitizeFilename(const std::string& filename);
    bool                            directoryExists(const std::string& path);
    bool                            createDirectory(const std::string& path);
};

#endif
