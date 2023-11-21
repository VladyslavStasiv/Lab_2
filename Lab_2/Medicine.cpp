#include "Medicine.h"

Medicine::Medicine(std::string TheNameOfTheDrug, std::string instruction, double value)
{
	this->TheNameOfTheDrug = TheNameOfTheDrug;
	this->instruction = instruction;
	this->value = value;
}

std::string Medicine::GetName()
{
	return TheNameOfTheDrug;
}

void Medicine::SetName(std::string TheNameOfTheDrug)
{
	this->TheNameOfTheDrug = TheNameOfTheDrug;
}

std::string Medicine::GetInstruction()
{
	return instruction;
}

void Medicine::SetInstruction(std::string instruction)
{
	this->instruction = instruction;
}

double Medicine::GetValue()
{
	return value;
}

void Medicine::SetValue(double value)
{
	this->value = value;
}

void Medicine::ShowInformation()
{
	std::cout << "Назва препарату: " << GetName() << std::endl;
	std::cout << "Інструкція: " << GetInstruction() << std::endl;
	std::cout << "Вартість: " << GetValue() << std::endl;
}