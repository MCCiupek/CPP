#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* arr[100];
	//const Animal y;
	const Cat* j = new Cat();
	const Dog* i = new Dog();

	for (int x = 0; x < 50; x++)
		arr[x] = new Dog;

	for (int x = 50; x < 100; x++)
		arr[x] = new Cat;

	for (int x = 0; x < 100; x++)
		delete arr[x];

	delete i;
	delete j; 

	return 0;
}