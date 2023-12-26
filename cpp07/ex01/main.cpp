#include "iter.hpp"

template <typename T>
void    ft_print_arr(T& arr, size_t size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    std::cout << "befor increment:\n";
    ::ft_print_arr(arr, 5);
    std::cout << "after increment:\n";
    ::iter(arr, 5, &::ft_increment);
    ::ft_print_arr(arr, 5);

    std::cout << "befor decrement:\n";
    ::ft_print_arr(arr, 5);
    std::cout << "after decrement:\n";
    ::iter(arr, 5, &::ft_decrement);
    ::ft_print_arr(arr, 5);

    return (0);
}