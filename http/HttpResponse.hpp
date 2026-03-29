#ifndef HTTPRESPONSE_HPP
#define HTTPRESPONSE_HPP

#include <string>
#include <map>

class HttpResponse
{
private:
    std::string _version;   // e.g., "HTTP/1.1"
    std::string _status;    // e.g., "200 OK"
    std::map<std::string, std::string> _headers;
    std::string _body;
    
public:
    HttpResponse();
    ~HttpResponse();
    
    // Setters
    void setVersion(const std::string& version);
    void setStatus(const std::string& status);
    void addHeader(const std::string& key, const std::string& value);
    void setBody(const std::string& body);
    
    // Getters
    const std::string& getVersion() const;
    const std::string& getStatus() const;
    const std::map<std::string, std::string>& getHeaders() const;
    const std::string& getBody() const;
    
    // Build the raw HTTP response string
    std::string buildRawResponse() const;
};

#endif
