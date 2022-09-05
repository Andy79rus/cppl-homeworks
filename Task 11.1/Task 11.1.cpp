#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void move_vectors(std::vector<T>& result, std::vector<T>& source)
{
	result.clear();
	result.resize(source.size());
	auto it = result.begin();
	for_each(source.cbegin(), source.cend(), [&it](const auto& i) {*it = i; ++it; });
	source.clear();
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "one: ";
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	move_vectors(two, one);

	std::cout << "two: ";
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "one: ";
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}