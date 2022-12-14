#include <iostream>
#include <functional>
#include <windows.h>
#include <iomanip>
#include <vector>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	constexpr auto PI = 3.1415926;

	std::vector<int> angles = { 30, 60, 90 };

	std::cout << std::fixed << std::setprecision(7);
	std::cout << "[Входные данные]: ";
	for (const auto& angle : angles)
	{
		std::cout << angle << " * " << PI << " / 180, ";
	}
	std::cout << "// перевод из градусов в радианы";
	std:: cout << std::endl;

	std::vector<std::function<void(int)>> functions;

	auto sin = [](int angle)
	{
		std::cout << "sin: " << std::sin(angle * PI / 180) << " ";
	};

	auto cos = [](int angle)
	{
		std::cout << "cos: " << std::cos(angle * PI / 180) << " ";
	};

	functions.push_back(sin);
	functions.push_back(cos);

	std::cout << "[Выходные данные]: " << std::endl;

	std::cout << std::defaultfloat;

	for (const auto& angle : angles)
	{
		std::cout << angle*PI/180 << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}

	return 0;
}