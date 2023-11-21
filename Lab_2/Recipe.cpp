#include "Recipe.h"

Recipe::Recipe()
{
	list1.push_back("Парацетамол");
	list1.push_back("Новірин");
	list1.push_back("Анальгін");
	list1.push_back("Стрепсілс");
	list1.push_back("Комбігрип");
}

void Recipe::ErorChecing()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
}

void Recipe::ShowInformation()
{
	std::cout << "Список потрібних ліків: " << std::endl;
	int i = 1;
	for (std::string medicines : list1)
	{
		std::cout << i <<" " << medicines << std::endl;
		i++;
	}
	std::cout << std::endl;
}

std::vector<std::string> Recipe::changeRecipe()
{
	std::cout << "Ви хочете редагувати весь рецепт, чи лиш частину?" << std::endl;
	ShowInformation();
	unsigned choice;
	bool stopWork = false;
	while (stopWork == false)
	{
		std::cout << "1. Вийти" << std::endl;
		std::cout << "2. Редагувати весь рецепт" << std::endl;
		std::cout << "3. Дописати ще 1 або кілька препаратів" << std::endl;
		std::cout << "4. Видалити 1 чи кілька препаратів" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		ErorChecing();
		switch (choice)
		{
		case 1: stopWork = true; break;
		case 2: list1.clear(); addItem(); break;
		case 3: addItem(); break;
		case 4: deleteItem(); break;
		default: std::cout << "Помилка при виборі пункту меню." << std::endl; break;
		}
	}
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::deleteItem()
{
	bool stopWork = false;
	int n;
	unsigned choice;
	while (stopWork == false)
	{
		std::cout << "Який препарат ви хочете видалити з рецепту?" << std::endl;
		ShowInformation();
		std::cin >> n;
		std::cout << std::endl;
		ErorChecing();
		while (n <= 0 || n > list1.size())
		{
			std::cout << "Ви ввели некоректне значення, спробуйте ще раз." << std::endl;
			std::cin >> n;
			std::cout << std::endl;
		}
		list1.erase(list1.begin()+(n - 1));
		std::cout << "Елемент успішно видалено." << std::endl;
		bool stopWork1 = false;
		while (stopWork1 == false)
		{
			std::cout << "Бажаєте продовжити видалення?" << std::endl;
			std::cout << "1. Так" << std::endl;
			std::cout << "2. Ні" << std::endl;
			std::cin >> choice;
			std::cout << std::endl;
			ErorChecing();
			switch (choice)
			{
			case 1: stopWork1 = true; break;
			case 2: stopWork = true;  stopWork1 = true; break;
			default: std::cout << "Помилка при виборі пункту меню." << std::endl; break;
			}
		}
	}
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::addItem()
{
	
	std::cout << "Яку кількість препаратів ви хочете записати в рецепт?" << std::endl;
	unsigned n;
	std::cin >> n;
	std::cout << std::endl;
	ErorChecing();
	std::cout << "Введіть назви препаратів:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::string name;
		std::cin >> name;
		list1.push_back(name);
	}
	std::cout << std::endl;
	std::cout << "Рецепт успішно відредаговано." << std::endl;
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::EditRecipe()
{
	ShowInformation();
	bool stopWork = false;
	unsigned choice;
	while (stopWork == false)
	{
		std::cout << "Виберіть, що саме ви хочете зробити:" << std::endl;
		std::cout << "1. Вийти" << std::endl;
		std::cout << "2. Перейти до редагування рецепту" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		ErorChecing();
		switch (choice)
		{
		case 1: stopWork = true; break;
		case 2: changeRecipe(); break;
		default: std::cout << "Помилка при виборі пункту меню." << std::endl; break;
		}
	}
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::GetList()
{
	return std::vector<std::string>(list1);
}
