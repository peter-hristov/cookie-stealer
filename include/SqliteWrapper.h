#ifndef SQLITEWRAPPER_H
#define SQLITEWRAPPER_H


#include "../sqlite3.h"
#include "Cookie.h"
#include <iostream>
#include <vector>

using namespace std;

class SqliteWrapper
{
    public:

        static std::vector<Cookie> printCookies(const char*, int);


        SqliteWrapper();
        virtual ~SqliteWrapper();
    protected:
    private:
};

#endif // SQLITEWRAPPER_H
