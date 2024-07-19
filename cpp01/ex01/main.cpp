#include "Zombie.hpp"

int main()
{
    Zombie  *zombie;

    zombie = zombieHorde(7, "yassir");
    for (int i = 0; i < 7; i++)
        zombie[i].announce();
    return (0);
}