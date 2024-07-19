#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif