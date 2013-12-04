#ifndef EXEPS_H
#define EXEPS_H
#include <exception>

class Exeps:public std::exception
{
    const char *what()const throw()
    {
        return "removing contact from empty banlist\n";
    }
};

#endif // EXEPS_H
