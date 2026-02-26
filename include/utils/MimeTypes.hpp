/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MimeTypes.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIME_TYPES_HPP
#define MIME_TYPES_HPP

#include <string>
#include <map>

class MimeTypes
{
public:
    static MimeTypes&   getInstance();
    
    std::string         getMimeType(const std::string& extension) const;
    std::string         getMimeTypeByPath(const std::string& path) const;
    std::string         getExtension(const std::string& mimeType) const;
    bool                isTextType(const std::string& mimeType) const;
    bool                isBinaryType(const std::string& mimeType) const;

private:
    MimeTypes();
    MimeTypes(const MimeTypes& other);
    MimeTypes& operator=(const MimeTypes& other);
    ~MimeTypes();

    void                initMimeTypes();
    std::string         getFileExtension(const std::string& path) const;
    std::string         toLower(const std::string& str) const;

    std::map<std::string, std::string>  _mimeTypes;
    std::map<std::string, std::string>  _extensions;
    static const std::string            DEFAULT_MIME_TYPE;
};

#endif
