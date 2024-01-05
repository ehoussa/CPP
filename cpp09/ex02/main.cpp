#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

int main(int ac, char **av) {

    try
    {
        if (ac > 1) {
            std::vector<Data>   vc;
            std::deque<Data>    dc;
            Data                dt;
            for (int i = 1; i < ac; ++i) {
                for (int x = 0; av[i][x]; ++x) {
                    if (av[i][x] < 48 || av[i][x] > 57)
                        throw("Error");
                }
                dt.value = std::atoi(av[i]);
                vc.push_back(dt);
                dc.push_back(dt);
            }
            //////////// check is sorted
            ////// canonical form
            std::cout << "Before: ";
            for (size_t z = 0; z < vc.size(); ++z) {
                std::cout << vc[z].value << " ";
            }
            std::cout << std::endl;

            std::clock_t start = std::clock();
            PmergeMe    srt(vc);
            std::clock_t end = std::clock();

            std::clock_t start2 = std::clock();
            PmergeMe    srt2(dc);
            std::clock_t end2 = std::clock();

            std::cout << "After: ";
            srt2.printSd();
            std::cout << std::endl;
            // srt.printSd();

            std::cout << "Time to process a range of " << ac << " elements with std::vector : " << (((double)(end - start)) / CLOCKS_PER_SEC) * 1000000 << std::endl;
            std::cout << "Time to process a range of " << ac << " elements with std::deque : " << (((double)(end2 - start2)) / CLOCKS_PER_SEC) * 1000000 << std::endl;
        }
    }
    catch(const char * e)
    {
        std::cerr << e << '\n';
    }

    return (0);
}