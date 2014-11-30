#include "FilesystemWrapper.h"

std::vector<std::string> FilesystemWrapper::Users = std::vector<std::string>();
std::vector<std::string> FilesystemWrapper::CookiePathsFirefox = std::vector<std::string>();
std::vector<std::string> FilesystemWrapper::CookiePathsChrome = std::vector<std::string>();

void FilesystemWrapper::getCookiePathsFirefox()
{
    using namespace boost::filesystem;

    std::vector<std::string> cookies;

    for(std::vector<std::string>::iterator i = Users.begin() ; i!=Users.end() ; i++) {

        std::string p = "C:\\Users\\" + *i +"\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles";

        if (exists(p) && is_directory(p)) {
            std::vector<std::string> profiles = getAllSubdirs(p);

            if (profiles.size() < 1) return;

            for(std::vector<std::string>::iterator j = profiles.begin() ; j!=profiles.end() ; j++) {
                std::string t = p + '\\' + *j + '\\' + "cookies.sqlite";
                if (exists(p)) {
                    cookies.push_back(t);
                }
            }
        }
    }

    CookiePathsFirefox = cookies;
}

void FilesystemWrapper::getCookiePathsChrome()
{
    using namespace boost::filesystem;

    std::vector<std::string> cookies;

    for(std::vector<std::string>::iterator i = Users.begin() ; i!=Users.end() ; i++) {

        // C:\\Users\\Peter\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Cookies
        //std::string p = "C:\\Users\\" + *i +"\\AppData\\Local\\Google\\Chrome\\User\ Data";
        std::string p = "C:\\Users\\" + *i + "\\AppData\\Local\\Google\\Chrome\\User Data";

        if (exists(p) && is_directory(p)) {
            std::vector<std::string> profiles = getAllSubdirs(p);

            if (profiles.size() < 1) return;

            for(std::vector<std::string>::iterator j = profiles.begin() ; j!=profiles.end() ; j++) {
                std::string t = p + '\\' + *j + '\\' + "Cookies";
                //std::cout << t << std::endl;
                if (exists(p)) {
                    cookies.push_back(t);
                }
            }
        }
    }

    CookiePathsChrome = cookies;
}



void FilesystemWrapper::getUsers(std::string p)
{
    Users = getAllSubdirs(p);

}

std::vector<std::string> FilesystemWrapper::getAllSubdirs(std::string p)
{
    using namespace boost::filesystem;
    std::vector<std::string> r;
    std::vector<path> v;
    try
    {
        if (exists(p) && is_directory(p)) {
            copy(directory_iterator(p), directory_iterator(), back_inserter(v));

            for(std::vector<path>::iterator i = v.begin() ; i!=v.end() ; i++) {
                std::string a = i->string();
                a = a.substr(a.find_last_of('\\') + 1);
                r.push_back(a);
            }
        }
    }
    catch (const filesystem_error& ex)
    {
        std::cout << ex.what() << '\n';
    }

    return r;
}

void FilesystemWrapper::print(std::vector<std::string> U)
{
    // "C:\\Users\\Peter\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\zyf0bi9h.default"
    for(std::vector<std::string>::iterator i = U.begin() ; i!=U.end() ; i++) {
        std::cout << *i << std::endl;
    }
}
