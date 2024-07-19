#include "PhoneBook.hpp"

void PhoneBook::Add(std::string str, int wich, int index)
{
    contact[index].setContact(str, wich);
}

std::string PhoneBook::Search(int wich, int index)
{
    return (contact[index].getContact(wich));
}