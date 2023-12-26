#include "Array.hpp"


int main(void)
{
	Array<int>	a(3);
	Array<int>	b(3);

    //print a
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}

    //print b
	std::cout << std::endl;
	for (size_t i = 0; i < b.size(); i++) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	std::cout << std::endl;
	std::cout << "AFTER FILLING A WITH 1" << std::endl;
    //print a
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}
	std::cout << std::endl;
    //print b
	for (size_t i = 0; i < b.size(); i++) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}
	b = a;
	std::cout << "AFTER B = A" << std::endl;
    //print a
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}
	std::cout << std::endl;
    //print b
	for (size_t i = 0; i < b.size(); i++) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}
    try {
        std::cout << a[a.size() + 1] << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}
