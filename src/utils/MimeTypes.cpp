/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MimeTypes.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/MimeTypes.hpp"

const std::string MimeTypes::DEFAULT_MIME_TYPE = "application/octet-stream";

MimeTypes::MimeTypes()
{
}

MimeTypes::MimeTypes(const MimeTypes& other)
{
    *this = other;
}

MimeTypes& MimeTypes::operator=(const MimeTypes& other)
{
    if (this != &other)
    {
        _mimeTypes = other._mimeTypes;
        _extensions = other._extensions;
    }
    return *this;
}

MimeTypes::~MimeTypes()
{
}

MimeTypes& MimeTypes::getInstance()
{
    static MimeTypes instance;
    return instance;
}

std::string MimeTypes::getMimeType(const std::string& extension) const
{
    (void)extension;
    return DEFAULT_MIME_TYPE;
}

std::string MimeTypes::getMimeTypeByPath(const std::string& path) const
{
    (void)path;
    return DEFAULT_MIME_TYPE;
}

std::string MimeTypes::getExtension(const std::string& mimeType) const
{
    (void)mimeType;
    return "";
}

bool MimeTypes::isTextType(const std::string& mimeType) const
{
    (void)mimeType;
    return false;
}

bool MimeTypes::isBinaryType(const std::string& mimeType) const
{
    (void)mimeType;
    return false;
}

void MimeTypes::initMimeTypes()
{
}

std::string MimeTypes::getFileExtension(const std::string& path) const
{
    (void)path;
    return "";
}

std::string MimeTypes::toLower(const std::string& str) const
{
    (void)str;
    return "";
}
