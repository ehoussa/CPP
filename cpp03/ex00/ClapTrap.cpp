#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "default constructor called" << std::endl;
    name = "anon";
    attack_damage = 0;
    hit_point = 10;
    energy_point = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "parameters constructor called" << std::endl;
    this->name = name;
    attack_damage = 0;
    hit_point = 10;
    energy_point = 10;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energy_point && this->hit_point)
    {
        std::cout << "ClapTrap" << this->name << "attacks" << target << "causing" << this->attack_damage << "points of damage!" << std::endl;
        this->energy_point--;
    }
    else
        std::cout << "No energy point or health" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap" << this->name << "take Damage" << std::endl;
    if (this->hit_point)
        this->hit_point--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
     if (this->energy_point && this->hit_point)
    {
        std::cout << "ClapTrap" << this->name << "repairing" << std::endl;
        this->hit_point += amount;
        this->energy_point--;
    }
    else
        std::cout << "No energy point or health" << std::endl;
}
