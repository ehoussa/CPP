#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon &a1) {
    a = &a1;
}

void    HumanB::attack() {
    if (a)
        std::cout << name << " attacks with their " << a->getType() << std::endl;
    else
        std::cout << "No weapon" << std::endl;
}

HumanB::HumanB(std::string name2) {
    name = name2;
}
