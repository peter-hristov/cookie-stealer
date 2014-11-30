#include "Cookie.h"

Cookie::Cookie(std::string name,std::string value,std::string expires)
{
    this->name = name;
    this->value = value;
    this->expires = expires;
}

Cookie::~Cookie()
{
    //dtor
}
