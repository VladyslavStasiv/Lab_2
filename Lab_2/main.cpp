#include "Pharmacy.h"
#include "Recipe.h"

using namespace std;

int  main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t\t\t\t\t\tЛабораторна робота № 2" << endl;
	unsigned choice;
	bool stopWork = false;
	Recipe recipe;
	Pharmacy pharmacy;
	vector<string> result;
	while (stopWork == false)
	{
		cout << "1. Вихід" << endl;
		cout << "2. Переглянути рецепт" << endl;
		cout << "3. Редагувати рецепт" << endl;
		cout << "4. Перевірити наявність препарату" << endl;
		cout << "5. Переглянути кошик" << endl;
		cin >> choice;
		if (std::cin.fail()) 
		{
			std::cin.clear(); 
			std::cin.ignore(INT_MAX, '\n'); 
		}
		switch (choice)
		{
		case 1: stopWork = true; break;
		case 2: recipe.ShowInformation(); break;
		case 3: recipe.EditRecipe(); break;
		case 4: pharmacy.SearchMedicine(); break;
		case 5: result = pharmacy.find(recipe);
			for (string drug : result)
			{
				cout << drug << endl;
			}
			cout << endl; break;
		default: cout << "Помилка при виборі пункту меню." << endl << endl; break;
		}
	}
	system("pause");
	return 0;
}