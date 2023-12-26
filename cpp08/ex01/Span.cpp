#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <limits>

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
    std::vector<int> shortest_value;

    for (size_t i = 1; i < vc.size(); ++i)
        shortest_value.push_back(vc[i] - vc[i - 1]);

    return (*(std::min_element(shortest_value.begin(), shortest_value.end())));
}

int Span::longestSpan() const {
    return (*(std::max_element(vc.begin(), vc.end())) - *(std::min_element(vc.begin(), vc.end())));
}
