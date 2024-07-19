#include "HumanA.hpp"


HumanA::HumanA(std::string name2, Weapon &a1) : a(a1) {
    name = name2;
}

void    HumanA::attack() {
    std::cout << name << "attacks with their " << a.getType() << std::endl;
}
