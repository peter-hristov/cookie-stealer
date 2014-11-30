#ifndef FILESYSTEMWRAPPER_H
#define FILESYSTEMWRAPPER_H


#include <boost/filesystem.hpp>
#include <vector>
#include <iostream>
#include <string>

class FilesystemWrapper
{
    public:
        static std::vector<std::string> Users;
        static std::vector<std::string> CookiePathsFirefox;
        static std::vector<std::string> CookiePathsChrome;

        static void getUsers(std::string);
        static void print(std::vector<std::string>);
        static void getCookiePathsFirefox();
        static void getCookiePathsChrome();
        static std::vector<std::string> getAllSubdirs(std::string);

        FilesystemWrapper();
        virtual ~FilesystemWrapper();
    protected:
    private:
};

#endif // FILESYSTEMWRAPPER_H
