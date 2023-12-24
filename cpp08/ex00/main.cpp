#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define CYAN	"\e[36m"

template <typename T>
void    ft_search(std::string containerType, T const & container, int tofind) {
    typename T::const_iterator a;

    std::cout << GREEN << "Searching for " << tofind << RESET << std::endl;
    std::cout << YELLOW << containerType << " container: ";
    for (a = container.begin(); a != container.end(); a++) {
        std::cout << "[" << *a << "] " ;
    }
    std::cout << RESET << std::endl;
    try
    {
        easyfind(container, tofind);
        std::cout << "OK Found "  << tofind << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main() {
    {
        std::cout << RED "********** TEST VECTOR CONTAINER **********" RESET << std::endl;
        std::vector<int> vc;

        for (int i = -7; i < 13; i++)
            vc.push_back(i * 3);

        ft_search("Vector", vc, 21);
        ft_search("Vector", vc, 21000);
    }
    {
        std::cout << RED "********** TEST LIST CONTAINER **********" RESET << std::endl;
        std::list<int> lc;

        for (int i = -7; i < 13; i++)
            lc.push_back(i * 3);

        ft_search("List", lc, 21);
        ft_search("List", lc, 21000);
    }
    return (0);
}