#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <limits>

class Recipe
{
	std::vector<std::string> list1;
	std::vector<std::string> deleteItem();
	std::vector<std::string> changeRecipe();
	std::vector<std::string> addItem();
	void ErorChecing();
public:
	Recipe();
	void ShowInformation();
	std::vector<std::string> EditRecipe();
	std::vector<std::string> GetList();
};

