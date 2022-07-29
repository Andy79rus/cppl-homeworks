// Cинтаксические ошибки:
/*
#include <iostream>

int main()
{
	for (int i = 0; i < 10, ++i)
	{
		if (i % 2) std::cout << i
		if (i >= 5) std::cout << i " больше 5" << std::endl;
}
*/

// Семантические ошибки:
/*
#include <iostream>

int main()
{
	for (int i = 0; i < 10; +i)
	{
		if (i % 2) std::cout << i << std::endl;
		if (i >= 5) std::cout << i << " больше 5" << std::endl;
	}
		
}
*/

// Ошибка линковки:
/*
test.h
int f(int n);


test.cpp

#include <iostream>
#include "test.h"

int f(bool n)
{}

int Main()
{
	for (int i = 0; i < 10; +i)
	{
		if (i % 2) std::cout << i << std::endl;
		if (i >= 5) std::cout << i << " больше 5" << std::endl;
		int m = f(i);
	}
	return 0;
}
*/