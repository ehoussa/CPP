#ifndef BIT
#define BIT
#include <iostream>
#include <vector>
#include <deque>
#include <utility>

struct Data {
    int value;
    std::vector<int> valuesVector;

    bool    operator< (const Data & other) {
        return value < other.value;
    }
};

class PmergeMe {
    private:
        std::vector<Data> sorted;
        std::deque<Data> sorted2;
    public:
                PmergeMe(std::vector<Data> &vtdate);
                PmergeMe(std::deque<Data> &vtdate);
        void    ft_sortv(std::vector<Data> &dqdate);
        void    ft_sortd(std::deque<Data> &dqdate);
        void    printSv() {
            for (size_t i = 0; i < sorted.size(); i++) {
                std::cout << sorted[i].value << " ";
            }
        }
        void    printSd() {
            for (size_t i = 0; i < sorted2.size(); i++) {
                std::cout << sorted2[i].value << " ";
            }
        }
};

#endif