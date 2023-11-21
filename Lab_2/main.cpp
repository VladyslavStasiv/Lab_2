#include "Pharmacy.h"
#include "Recipe.h"

using namespace std;

int  main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t\t\t\t\t\t����������� ������ � 2" << endl;
	unsigned choice;
	bool stopWork = false;
	Recipe recipe;
	Pharmacy pharmacy;
	vector<string> result;
	while (stopWork == false)
	{
		cout << "1. �����" << endl;
		cout << "2. ����������� ������" << endl;
		cout << "3. ���������� ������" << endl;
		cout << "4. ��������� �������� ���������" << endl;
		cout << "5. ����������� �����" << endl;
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
		default: cout << "������� ��� ����� ������ ����." << endl << endl; break;
		}
	}
	system("pause");
	return 0;
}