#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = newZombie("zazzaz");
    zombie->announce();
    delete(zombie);
    randomChump("baaza");
    return (0);
}