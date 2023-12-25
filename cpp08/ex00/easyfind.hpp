#ifndef EAS
#define EAS

template <typename T>
typename T::const_iterator	easyfind(T const & container, int const element)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw (std::out_of_range("Element not found in container."));
	return (it);
}

#endif