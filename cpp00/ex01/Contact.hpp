#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>


class Contact {
	private:
		std::string	first;
		std::string	last;
		std::string	nick;
		std::string	phone;
		std::string	darkset;
	public:
		void			setContact(std::string str, int wich);
		std::string		getContact(int wich);
};

#endif