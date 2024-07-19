#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define SIZEAR	8

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[SIZEAR];
	public:
		void		Add(std::string str, int wich, int index);
		std::string	Search(int wich, int index);
};

#endif