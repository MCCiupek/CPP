#include <iostream>
#include <cctype>
#include <exception>

template<typename T>
void iter(T *arr, size_t len, void (*f)(T const &elem)) {

	if (!f || !arr)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void display(T const &value)
{
	std::cout << value << " ";
}
