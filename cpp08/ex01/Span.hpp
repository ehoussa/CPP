#ifndef SPAN
#define SPAN
#include <vector>

class Span {
    private:
        std::vector<int>    vc;
        unsigned int        sizevc;
    public:
                Span();
                Span(unsigned int sizevc);
                Span(Span const &copy);
                ~Span();
        Span    &operator=(Span const & assign);
        void    addNumber(unsigned int element);
        int     shortestSpan() const;
        int     longestSpan() const;
};

#endif