#include "BitcoinExchange.hpp"

int main() {
    BitcoinExchange btc;

    try
    {
        btc.ft_fillmap();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}