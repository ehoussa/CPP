#include "Harl.hpp"

void    Harl::debug() {
    std::cout << "debug" << std::endl;
}

void    Harl::info() {
    std::cout << "info" << std::endl;
}

void    Harl::warning() {
    std::cout << "warning" << std::endl;
}

void    Harl::error() {
    std::cout << "error" << std::endl;
}

void Harl::complain(std::string str) {
    void (Harl::*deb)() = &Harl::debug;
    void (Harl::*inf)() = &Harl::info;
    void (Harl::*war)() = &Harl::warning;
    void (Harl::*err)() = &Harl::error;
    int i;


    i = 1;
    while (i && str == "DEBUG")
    {
        (this->*deb)();
        i = 0;
    }
    while (i && str == "INFO")
    {
        (this->*inf)();
        i = 0;
    }
    while (i && str == "WARNING")
    {
        (this->*war)();
        i = 0;
    }
    while (i && str.compare("ERROR") == 0)
    {
        (this->*err)();
        i = 0;
    }
}