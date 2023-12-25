#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>

Span::Span() {
    this->sizevc = 0;
}

Span::Span(unsigned int sizevc) {
    this->sizevc = sizevc;
}

Span::Span(Span const &copy) {
    this->sizevc = copy.sizevc;
    this->vc = copy.vc;
}

Span::~Span() {}

Span &Span::operator=(Span const &assign) {
    this->sizevc = assign.sizevc;
    this->vc = assign.vc;
    return (*this);
}

void Span::addNumber(unsigned int element) {
    if (this->sizevc != 0) {
        this->vc.push_back(element);
        this->sizevc--;
        sort(this->vc.begin(), this->vc.end());
    } else
        throw (std::out_of_range("Error"));
}

int Span::shortestSpan() const {
    int shortes;
    int tmp;
    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator itt;
    std::vector<int>::const_iterator it2;

    for (it = vc.begin(); it != vc.end(); it++) {
        itt = it;
        for (it2 = ++itt; it2 != vc.end(); it2++) {
            tmp = *it2 - *it;
            if (it == vc.begin())
                shortes = tmp;
            else
                if (shortes > tmp)
                    shortes = tmp;
        }
            
    }
    return (shortes);
}

int Span::longestSpan() const {
    int longest;
    int tmp;
    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator itt;
    std::vector<int>::const_iterator it2;

    for (it = vc.begin(); it != vc.end(); it++) {
        itt = it;
        for (it2 = ++itt; it2 != vc.end(); it2++) {
            tmp = *it2 - *it;
            if (it == vc.begin())
                longest = tmp;
            else
                if (longest < tmp)
                    longest = tmp;
        }
            
    }
    return (longest);
}
