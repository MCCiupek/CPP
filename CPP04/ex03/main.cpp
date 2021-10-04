#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {

	std::cout << "----- SUBJECT TESTS -----" << std::endl << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "----- OTHER TESTS -----" << std::endl << std::endl;

	IMateriaSource *materia_source = new MateriaSource();

	std::cout << "1. learn materias to src: " << std::endl;
	materia_source->learnMateria(new Ice());
	materia_source->learnMateria(new Ice());
	materia_source->learnMateria(new Ice());
	materia_source->learnMateria(new Cure());
	materia_source->learnMateria(new Cure());

	ICharacter *stas = new Character("Stas");
	ICharacter *garik = new Character("Garik");
	AMateria *materia;

	std::cout << std::endl;
	std::cout << "2. create materias and equip characters: " << std::endl;
	materia = materia_source->createMateria("ice");
	stas->equip(materia);
	materia = materia_source->createMateria("cure");
	stas->equip(materia);

	std::cout << std::endl;
	std::cout << "3.1. use materias: " << std::endl;
	stas->use(0, *garik);
	stas->use(1, *garik);

	std::cout << std::endl;
	std::cout << "3.2. try use unexisting materias: " << std::endl;
	stas->use(3, *garik);

	std::cout << std::endl;
	std::cout << "3.3. try use unequiped materias: " << std::endl;
	stas->unequip(1);
	stas->use(1, *garik);
	stas->equip(materia);

	materia = materia_source->createMateria("ice");
	stas->equip(materia);
	materia = materia_source->createMateria("cure");
	stas->equip(materia);
	materia = materia_source->createMateria("ice");
	stas->equip(materia);

	std::cout << std::endl;
	std::cout << "3.4. try use indexed and non indexed materias: " << std::endl;
	stas->use(0, *garik);
	stas->use(1, *garik);
	stas->use(2, *garik);
	stas->use(3, *garik);
	stas->use(4, *garik);
	stas->use(-4, *garik);

	delete materia;
	delete materia_source;
	delete stas;
	delete garik;
	
	return 0;
}