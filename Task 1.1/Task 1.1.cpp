#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> v_arr = { 4, 7, 9, 14, 12 };

	std::cout << "Входные данные: ";
	std::for_each(v_arr.cbegin(), v_arr.cend(), [](const int& n) { std::cout << n << " "; });
	std::cout << std::endl;
	
	std::cout << "Выходные данные: ";
	auto iter = v_arr.begin();
	std::for_each(v_arr.cbegin(), v_arr.cend(), [&iter](const int& n) { if (1 == n % 2) { *iter = n * 3; } iter++; });
	std::for_each(v_arr.cbegin(), v_arr.cend(), [](const int& n) { std::cout << n << " "; });
	std::cout << std::endl;

	return 0;
}