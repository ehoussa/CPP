#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>


int main(int ac, char **av) {
    uintptr_t uns;
    Data addr;

    (void)av;
    (void)ac;
    addr.value = 7;
    uns = Serializer::serialize(&addr);
    std::cout << "OG foo (Data) Address = " << &addr << std::endl << "dummy_str value = " << addr.value << std::endl;
    std::cout << std::endl;
    std::cout << "Reinterpreted foo value = " << uns << std::endl;
    std::cout << std::endl;
    Data *deserialized;
    deserialized = Serializer::deserialize(uns);
    std::cout << "Deserialized Address = " << deserialized << std::endl << "dummy_str value = " << deserialized->value << std::endl;
    return 0;
}