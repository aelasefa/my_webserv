/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCodes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_CODES_HPP
#define STATUS_CODES_HPP

#include <string>
#include <map>

class StatusCodes
{
public:
    static StatusCodes& getInstance();
    
    std::string         getReasonPhrase(int code) const;
    bool                isInformational(int code) const;
    bool                isSuccess(int code) const;
    bool                isRedirection(int code) const;
    bool                isClientError(int code) const;
    bool                isServerError(int code) const;
    bool                isError(int code) const;
    bool                isValid(int code) const;

    static const int OK = 200;
    static const int CREATED = 201;
    static const int NO_CONTENT = 204;
    static const int MOVED_PERMANENTLY = 301;
    static const int FOUND = 302;
    static const int SEE_OTHER = 303;
    static const int NOT_MODIFIED = 304;
    static const int TEMPORARY_REDIRECT = 307;
    static const int PERMANENT_REDIRECT = 308;
    static const int BAD_REQUEST = 400;
    static const int FORBIDDEN = 403;
    static const int NOT_FOUND = 404;
    static const int METHOD_NOT_ALLOWED = 405;
    static const int REQUEST_TIMEOUT = 408;
    static const int CONFLICT = 409;
    static const int LENGTH_REQUIRED = 411;
    static const int PAYLOAD_TOO_LARGE = 413;
    static const int URI_TOO_LONG = 414;
    static const int UNSUPPORTED_MEDIA_TYPE = 415;
    static const int INTERNAL_SERVER_ERROR = 500;
    static const int NOT_IMPLEMENTED = 501;
    static const int BAD_GATEWAY = 502;
    static const int SERVICE_UNAVAILABLE = 503;
    static const int GATEWAY_TIMEOUT = 504;
    static const int HTTP_VERSION_NOT_SUPPORTED = 505;

private:
    StatusCodes();
    StatusCodes(const StatusCodes& other);
    StatusCodes& operator=(const StatusCodes& other);
    ~StatusCodes();

    void                                initStatusCodes();
    std::map<int, std::string>          _statusCodes;
};

#endif
