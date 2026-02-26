/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCodes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webserv                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26                               #+#    #+#             */
/*   Updated: 2026/02/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/StatusCodes.hpp"

StatusCodes::StatusCodes()
{
}

StatusCodes::StatusCodes(const StatusCodes& other)
{
    *this = other;
}

StatusCodes& StatusCodes::operator=(const StatusCodes& other)
{
    if (this != &other)
    {
        _statusCodes = other._statusCodes;
    }
    return *this;
}

StatusCodes::~StatusCodes()
{
}

StatusCodes& StatusCodes::getInstance()
{
    static StatusCodes instance;
    return instance;
}

std::string StatusCodes::getReasonPhrase(int code) const
{
    (void)code;
    return "";
}

bool StatusCodes::isInformational(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isSuccess(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isRedirection(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isClientError(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isServerError(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isError(int code) const
{
    (void)code;
    return false;
}

bool StatusCodes::isValid(int code) const
{
    (void)code;
    return false;
}

void StatusCodes::initStatusCodes()
{
}
