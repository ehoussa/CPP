#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    static int rndm = 0;
    if (rndm == 3)
        rndm = 0;
    rndm++;

    switch (rndm) {
        case 1:
            std::cout << "Type " << "A" << " created." << std::endl;
            return (new A);
        case 2:
            std::cout << "Type " << "B" << " created." << std::endl;
            return (new B);
        case 3:
            std::cout << "Type " << "C" << " created." << std::endl;
            return (new C);
        default:
            break;
    }
    return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Invalid type" << std::endl;
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::exception& e) {}
    try {
        B &a = dynamic_cast<B &>(p);
        (void)a;
        std::cout << "B" << std::endl;
    } catch (std::exception& e) {}
    try {
        C &a = dynamic_cast<C &>(p);
        (void)a;
        std::cout << "C" << std::endl;
    } catch (std::exception& e) {}
}
