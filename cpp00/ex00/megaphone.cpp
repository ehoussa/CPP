#include <iostream>

namespace aaa {
	int a;
};

using namespace std;

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
		for (int x = 0; av[i][x]; x++)
			cout << (char)std::toupper(av[i][x]);
	cout << std::endl;
	return (0);
}