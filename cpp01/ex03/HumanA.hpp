#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA {
    private:
        Weapon &a;
        std::string name;
    public:
        void    attack();

        HumanA(std::string name2, Weapon &a1);
};
#endif
