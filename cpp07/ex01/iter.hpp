#ifndef ITE
#define ITE
#include <stdint.h>
#include <iostream>

template <typename T>
void    ft_increment(T& element) {
    element++;
}

template <typename T>
void    ft_decrement(T& element) {
    element--;
}

template <typename T>
void iter(T arr[], size_t size, void(*f)(T&)) {
    for (size_t i = 0; i < size; i++)
        f(arr[i]);
}

#endif