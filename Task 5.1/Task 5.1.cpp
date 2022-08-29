#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
T Squaring(T& a)
{
	a*=a;
	return a;
}

template <>
std::vector<int> Squaring(std::vector<int>& vect) {
	for (auto& i : vect)
		i *= i;
	return vect;
}

int main()
{
	int num = 5;

	std::cout << "[IN]: " << num << std::endl;

	Squaring(num);

	std::cout << "[OUT]: " << num << std::endl;

	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
	
	std::cout << "[IN]: ";
	std::for_each(arr.cbegin(), arr.cend() - 1, [](const int& n) { std::cout << n << ", "; });
		std::cout << *(arr.cend() - 1) << std::endl;

	Squaring(arr);

	std::cout << "[OUT]: ";
	std::for_each(arr.cbegin(), arr.cend() - 1, [](const int& n) { std::cout << n << ", "; });
	std::cout << *(arr.cend() - 1) << std::endl;

	return 0;
}