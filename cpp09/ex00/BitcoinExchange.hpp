#ifndef BIT
#define BIT
#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, std::string>  btcprice;
        std::string                         inputfile;
        std::string                         outputstr;
    public:
        void    ft_fillmap();
        void    ft_searchforprice(std::string &str1, std::string &str2, int x, std::string &line);
        void    ft_print();
};

#endif