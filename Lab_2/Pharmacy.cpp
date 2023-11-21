#include "Pharmacy.h"

Pharmacy::Pharmacy()
{
    list2.push_back(Medicine("Парацетамол", "Приймати по 1 таблетці 3 рази на добу", 30.2));
    list2.push_back(Medicine("Стрепсілс", "Приймати по 1 таблетці кожних 3-4 години", 90));
    list2.push_back(Medicine("Пульмолор", "Приймати по 1 таблетці 4 рази на добу", 66.6));
    list2.push_back(Medicine("Пульмобріз", "Приймати по 1 таблетці 4 рази на добу", 124.8));
    list2.push_back(Medicine("Нурофен", "Приймати по 1 таблетці 3 рази на добу", 134.3));
}

void Pharmacy::ShowInformation()
{
    for (auto& drug : list2)
    {
        drug.Medicine::ShowInformation();
        std::cout << std::endl;
    }
}

void Pharmacy::SearchMedicine()
{
    std::cout << "Введіть назву препарату, який шукаєте: " << std::endl;
    std::string name;
    std::cin >> name;
    bool found = false;
    double value1;
    std::cout << std::endl;
    for (auto drug : list2) 
    {
        if (drug.GetName() == name)
        {
            found = true;
            value1 = drug.GetValue();
            break;
        }
    }

    if (found) 
    {
        std::cout << "Препарат '" << name << "' в наявності. Ціна в грн: " << value1<< std::endl;
        basket.push_back(name);
    }
    else 
    {
        std::cout << "Препарат '" << name << "' не в наявності." << std::endl;
    }
}



std::vector<std::string> Pharmacy::find(Recipe listToFind)
{
    std::vector<std::string> result;
    for (std::string item : listToFind.GetList())
    {
        for (auto& medic : list2)
        {
            if (medic.GetName() == item)
            {
                result.push_back(medic.GetName());
            }
        }
    }
    if (result.empty())
    {
        std::cout << "Кошик пустий." << std::endl << std::endl;
    }
    return std::vector<std::string>(result);
}

void Pharmacy::buy(Recipe listToFind)
{
    std::vector<std::string> result;
    for (std::string item : listToFind.GetList())
    {
        for (auto& medic : list2)
        {
            if (medic.GetName() == item)
            {
                basket.push_back(medic.GetName());
            }
        }
    }
}
