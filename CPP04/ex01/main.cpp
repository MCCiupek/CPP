#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

int main()
{
	srand((unsigned)time(0));

	std::cout << "----- CONSTRUCTORS -----" << std::endl;
	Animal animal;
	const Animal* arr[100];
	const Cat* j = new Cat();
	const Dog* i = new Dog();

	for (int x = 0; x < 50; x++)
		arr[x] = new Dog;

	for (int x = 50; x < 100; x++)
		arr[x] = new Cat;

	std::cout << std::endl << "----- IDEAS -----" << std::endl;
	const std::string  * id = j->getBrain()->getIdeas();

	for (int x = 0; x < 100; x++)
		std::cout << id[x] << std::endl;
	
	std::cout << std::endl << "----- TESTS -----" << std::endl;

	std::cout << *j << std::endl;
	std::cout << *i << std::endl;

	std::cout << std::endl << "----- DESTRUCTORS -----" << std::endl;
	for (int x = 0; x < 100; x++)
		delete arr[x];

	delete i;
	delete j; 

	return 0;
}