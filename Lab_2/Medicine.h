#pragma once
#include <iostream>
#include <string>

class Medicine
{
	std::string TheNameOfTheDrug;
	std::string instruction;
	double value;
public:
	Medicine(std::string TheNameOfTheDrug, std::string instruction, double value);
	std::string GetName();
	void SetName(std::string TheNameOfTheDrug);

	std::string GetInstruction();
	void SetInstruction(std::string instruction);

	double GetValue();
	void SetValue(double value);

	void ShowInformation();
};