#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        const   std::string&  getType(void);
        void    setType(std::string type2);
        Weapon(std::string type3);
};

#endif
