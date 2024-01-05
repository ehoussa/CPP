#include "BitcoinExchange.hpp"

void BitcoinExchange::ft_fillmap() {
	std::ifstream file("data.csv");
	std::ifstream file2("h.txt");
	
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (!file2.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string str1;
		std::string str2;
		std::string nospace;
		int         check = 1;

		for (size_t i = 0; i < line.size(); ++i) {
			if (line[i] != ',' && check)
				str1 += line[i];
			else if (line[i] == ',')
				check = 0;
			else
				str2 += line[i];
		}
		//skip spaces  
		size_t a = str1.size();
		if (str1.size())
			while (a && a-- > 0 && (str1[a] == ' ' || str1[a] == 9));
		size_t b = 0;
		if (str1.size())
			while (b++ < str1.size() && (str1[b] == ' ' || str1[b] == 9));
		if (str1.size() && str1[b - 1] != ' ' && str1[b - 1] != 9)
			b--;
		for (size_t i = b; i <= a; ++i)
			nospace += str1[i];
		str1 = nospace;
		nospace.clear();
		a = str2.size();
		if (str2.size())
			while (a && a-- > 0 && (str2[a] == ' ' || str2[a] == 9));
		b = 0;
		if (str2.size())
			while (b++ < str2.size() && (str2[b] == ' ' || str2[b] == 9));
		if (str2.size() && str2[b - 1] != ' ' && str2[b - 1] != 9)
			b--;
		for (size_t i = b; i <= a; ++i)
			nospace += str2[i];
		str2 = nospace;          
		btcprice[str1] = str2;
	}
	int	x = 1;
	while (std::getline(file2, line)) {
		if (!line.size())
			continue;
		std::string str1;
		std::string str2;
		std::string nospace;
		std::string nospace2;
		int         check = 1;

		for (size_t i = 0; i < line.size(); ++i) {
			if (line[i] != '|' && check)
				str1 += line[i];
			else if (line[i] == '|')
				check = 0;
			else
				str2 += line[i];
		}
		//skip spaces 
		if (str1.size()) {
			size_t a = str1.size();
			if (str1.size())
				while (a && a-- > 0 && (str1[a] == ' ' || str1[a] == 9));
			size_t b = 0;
			if (str1.size())
				while (b++ < str1.size() && (str1[b] == ' ' || str1[b] == 9));
			if (str1.size() && str1[b - 1] != ' ' && str1[b - 1] != 9)
				b--;
			for (size_t i = b; i <= a; ++i)
				nospace += str1[i];
			str1 = nospace;
		}
		// nospace.clear();
		if (str2.size()) {
			size_t a = str2.size();
			if (str2.size())
				while (a && a-- > 0 && (str2[a] == ' ' || str2[a] == 9));
			size_t b = 0;
			if (str2.size())
				while (b++ < str2.size() && (str2[b] == ' ' || str2[b] == 9));
			if (str2.size() && str2[b - 1] != ' ' && str2[b - 1] != 9)
				b--;
			for (size_t i = b; i <= a; ++i)
				nospace2 += str2[i];
			str2 = nospace2;
		}
		ft_searchforprice(str1, str2, x, line);
		x = 0;
	}
}

void BitcoinExchange::ft_searchforprice(std::string &str1, std::string &str2, int x, std::string &line) {
	std::string yy;
	std::string mm;
	std::string dd;

	if (x && (str1 != "date" || str2 != "value"))
		throw std::runtime_error("Error: must use the following format: \"date | value\".");
	if (!x) {
		// split date
		size_t i = 0;
		while (i < str1.size() && str1[i] != '-')
			yy += str1[i++];
		i++;
		while (i < str1.size() && str1[i] != '-')
			mm += str1[i++];
		i++;
		while (i < str1.size())
			dd += str1[i++];
		//check if date empty
		if (!yy.length() || !mm.length() || !dd.length() || !str2.length()) {
			std::cout << "Error: bad input => " << line << std::endl;
			return;
		}
		//check if its char
		i = 0;
		for (size_t x = 0; x < yy.size(); ++x)
			if (yy[x] < 48 || yy[x] > 57)
				i = 1;
		for (size_t x = 0; x < mm.size(); ++x)
			if (mm[x] < 48 || mm[x] > 57)
				i = 1;
		for (size_t x = 0; x < dd.size(); ++x)
			if (dd[x] < 48 || dd[x] > 57)
				i = 1;
		if (i) {
			std::cout << "Error: bad input => " << line << std::endl;
			return;
		}
		//check if kabissa
		int	kabissa = 0;
		int	yyy = atoi(yy.c_str());
		if (!(yyy % 2)) {
			if (!(yyy % 2) && (yyy % 100))
				kabissa = 1;
		} else if (!(yyy % 2) && !(yyy % 100))
				if (!(yyy % 400) && !(yyy % 100))
					kabissa = 1;
		// check mm
		int mmm = atoi(mm.c_str());
		int ddd = atoi(dd.c_str());
		if ((mmm % 2) && mmm <= 12) { //31
			if (ddd > 31) {
				std::cout << "Error: bad date => " << line << std::endl;
				return;
			}
		} else if (mmm <= 12) { //30
			if (mmm == 2 && kabissa) { // kabissa -> YES
				if (ddd > 28) {
					std::cout << "Error: bad date => " << line << std::endl;
					return;
				}
			} else if (mmm == 2 && !kabissa) { // kabissa -> NO
				if (ddd > 29) {
					std::cout << "Error: bad date => " << line << std::endl;
					return;
				}
			} else if (mmm <= 12) {
				if (ddd > 30) {
					std::cout << "Error: bad date => " << line << std::endl;
					return;
				}
			}
		} else  {
			std::cout << "Error: bad date => " << line << std::endl;
			return;
		}
		// check str2
		if (str2.size() && (str2[0] < 48 || str2[0] > 57) && str2[0] != '-') {
			std::cout << "Error: bad input => " << line << std::endl;
			return;
		}
		if (str2[0] == '-' && str2.size() == 1) {
			std::cout << "Error: bad input => " << line << std::endl;
			return;
		}
		int checkpoint = 1;
		size_t y = 0;
		if (str2[0] == '-')
			y = 1;
		for (i = 0 + y; i < str2.size(); ++i) {
			if (str2[i] < 48 || str2[0] > 57) {
				if (str2[i] == '.' && checkpoint && i != (0 + y)) {
					checkpoint = 0;
					continue;
				}
				std::cout << "Error: bad input => " << line << std::endl;
				return;
			}
		}
		//check - and > 1000
		if (str2[0] == '-') {
			std::cout << "Error: not a positive number.\n";
			return;
		}
		std::map<std::string, std::string>::iterator it;
		it = this->btcprice.upper_bound(str1);
		if (it == this->btcprice.begin() || yy.size() < 4) {
			std::cout << "Error: Not in data base.\n";
			return;
		}
		--it;
		std::string pr;
		pr = it->second;
		std::stringstream ss;
		ss << str2;
		float val;
		ss >> val;
		if (val < 0 || val > 1000) {
			std::cout << "Error: too large a number.\n";
			return;
		}
		std::stringstream ss2;
		ss2 << pr;
		float price;
		ss2 >> price;
		ss2 << (val * price);
		std::string rs;
		ss2 << rs;
		std::cout << str1 << " => " << str2 << " = " << (val * price) << "\n";
	}
}
