#pragma once
#include "Medicine.h"
#include "Recipe.h"
#include <list>

class Pharmacy
{
	std::list<Medicine> list2;
	std::vector<std::string> basket;
public:
	Pharmacy();
	void ShowInformation();
	void SearchMedicine();
	std::vector<std::string>find(Recipe listToFind);
	void buy(Recipe listToFind);
};