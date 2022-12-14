#include "uniqueptr.h"
#include <iostream>

int main()
{
	int n = 20;

	int* ptr_n = &n;

	uniqueptr<int> up(ptr_n);

	std::cout << *up << std::endl;

	uniqueptr<int> up2 = std::move(up);

	// std::cout << *up << std::endl; //уже вызывает Access violation reading location

	std::cout << *up2 << std::endl;

	*up2 = 30;
	std::cout << *up2 << std::endl;

	uniqueptr<int> up3(std::move(up2));

	std::cout << *up3 << std::endl;
	*up3 = 40;

	ptr_n = up3.release();

	std::cout << *ptr_n << std::endl;

	return 0;
}