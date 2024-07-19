#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        void    announce(void);
        void    setName(std::string str);
        Zombie(){std::cout << "Hello My Friend !!!!\n";};
        Zombie(std::string n) {name = n;};
        ~Zombie() {std::cout << "hello\n";};
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif