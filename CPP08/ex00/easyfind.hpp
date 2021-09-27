#ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <algorithm>
# include <exception>

class ElemNotFound : public std::exception {
	public:
		const char * what() const throw() {
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator	easyfind(T & container, int n) {

	typename	T::iterator it;

	it = find (container.begin(), container.end(), n);
	if (it == container.end())
		throw ElemNotFound();
	return it;
}

#endif /* __EASYFIND_H__ */