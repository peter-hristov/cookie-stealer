#ifndef COOKIE_H
#define COOKIE_H

#include <string>

class Cookie
{
    public:
        long id;
        std::string baseDomain;
        long appId;
        long inBrowserElement;
        std::string name;
        std::string value;
        std::string host;
        std::string path;
        std::string expires;
        long lastAccessed;
        long creationTime;
        long isSecure;


        Cookie(std::string, std::string, std::string);
        virtual ~Cookie();
    protected:
    private:
};

#endif // COOKIE_H
