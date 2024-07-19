#include "Contact.hpp"

void Contact::setContact(std::string str, int wich)
{
    if (wich == 0)
        first = str;
    else if (wich == 1)
        last = str;
    else if (wich == 2)
        nick = str;
    else if (wich == 3)
        phone = str;
    else if (wich == 4)
        darkset = str;
}

std::string Contact::getContact(int wich)
{
    if (wich == 0)
        return (first);
    else if (wich == 1)
        return (last);
    else if (wich == 2)
        return (nick);
    else if (wich == 3)
        return (phone);
    else if (wich == 4)
        return (darkset);
    return (NULL);
}