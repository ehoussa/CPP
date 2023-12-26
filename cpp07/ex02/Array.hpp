#ifndef ARR
#define ARR

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T               *arr;
        unsigned int    size_arr;
    public:
                        Array(void);
                        Array(unsigned int n);
                        Array(Array const &copy);
        Array<T>        &operator=(Array const & assign);
        T               &operator[](unsigned int index);
        unsigned int    size() const;
                        ~Array();
};

template <typename T>
Array<T>::Array(void) {
    arr = NULL;
    this->size_arr = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    arr = new T[n];
    size_arr = n;
}

template <typename T>
Array<T>::Array(Array const &copy) {
    this->arr = new T[copy.size_arr];
    for (unsigned int i = 0; i < copy.size_arr; i++)
        arr[i] = copy.arr[i];
    this->size_arr = copy.size_arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const & assign) {
    if (this != &assign) {
        if (this->arr)
            delete[] this->arr;
        this->arr = new T[assign.size_arr];
        for (unsigned int i = 0; i < assign.size_arr; i++)
            arr[i] = assign.arr[i];
        this->size_arr = assign.size_arr;
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= size_arr) {
        throw std::out_of_range("Index out of range");
    }
    return (arr[index]);
}

template <typename T>
unsigned int    Array<T>::size() const {
    return (this->size_arr);
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

#endif