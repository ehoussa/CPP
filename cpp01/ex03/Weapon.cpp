#include "Weapon.hpp"

const std::string&    Weapon::getType() {
    return (type);   
}

void Weapon::setType(std::string type2) {
    type = type2;
}

Weapon::Weapon(std::string type3) {
    setType(type3);
}