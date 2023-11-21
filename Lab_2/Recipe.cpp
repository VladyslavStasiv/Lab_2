#include "Recipe.h"

Recipe::Recipe()
{
	list1.push_back("�����������");
	list1.push_back("������");
	list1.push_back("�������");
	list1.push_back("��������");
	list1.push_back("��������");
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
	std::cout << "������ �������� ���: " << std::endl;
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
	std::cout << "�� ������ ���������� ���� ������, �� ��� �������?" << std::endl;
	ShowInformation();
	unsigned choice;
	bool stopWork = false;
	while (stopWork == false)
	{
		std::cout << "1. �����" << std::endl;
		std::cout << "2. ���������� ���� ������" << std::endl;
		std::cout << "3. �������� �� 1 ��� ����� ���������" << std::endl;
		std::cout << "4. �������� 1 �� ����� ���������" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		ErorChecing();
		switch (choice)
		{
		case 1: stopWork = true; break;
		case 2: list1.clear(); addItem(); break;
		case 3: addItem(); break;
		case 4: deleteItem(); break;
		default: std::cout << "������� ��� ����� ������ ����." << std::endl; break;
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
		std::cout << "���� �������� �� ������ �������� � �������?" << std::endl;
		ShowInformation();
		std::cin >> n;
		std::cout << std::endl;
		ErorChecing();
		while (n <= 0 || n > list1.size())
		{
			std::cout << "�� ����� ���������� ��������, ��������� �� ���." << std::endl;
			std::cin >> n;
			std::cout << std::endl;
		}
		list1.erase(list1.begin()+(n - 1));
		std::cout << "������� ������ ��������." << std::endl;
		bool stopWork1 = false;
		while (stopWork1 == false)
		{
			std::cout << "������ ���������� ���������?" << std::endl;
			std::cout << "1. ���" << std::endl;
			std::cout << "2. ͳ" << std::endl;
			std::cin >> choice;
			std::cout << std::endl;
			ErorChecing();
			switch (choice)
			{
			case 1: stopWork1 = true; break;
			case 2: stopWork = true;  stopWork1 = true; break;
			default: std::cout << "������� ��� ����� ������ ����." << std::endl; break;
			}
		}
	}
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::addItem()
{
	
	std::cout << "��� ������� ��������� �� ������ �������� � ������?" << std::endl;
	unsigned n;
	std::cin >> n;
	std::cout << std::endl;
	ErorChecing();
	std::cout << "������ ����� ���������:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::string name;
		std::cin >> name;
		list1.push_back(name);
	}
	std::cout << std::endl;
	std::cout << "������ ������ ������������." << std::endl;
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::EditRecipe()
{
	ShowInformation();
	bool stopWork = false;
	unsigned choice;
	while (stopWork == false)
	{
		std::cout << "�������, �� ���� �� ������ �������:" << std::endl;
		std::cout << "1. �����" << std::endl;
		std::cout << "2. ������� �� ����������� �������" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		ErorChecing();
		switch (choice)
		{
		case 1: stopWork = true; break;
		case 2: changeRecipe(); break;
		default: std::cout << "������� ��� ����� ������ ����." << std::endl; break;
		}
	}
	return std::vector<std::string>(list1);
}

std::vector<std::string> Recipe::GetList()
{
	return std::vector<std::string>(list1);
}
