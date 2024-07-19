#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon *a;
        std::string name;
    public:
        void    setWeapon(Weapon &a1);
        void    attack();
        HumanB(std::string name2);
};

#endif
