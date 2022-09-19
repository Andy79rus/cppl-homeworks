#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void move_vectors(std::vector<T>& source, std::vector<T>& result)
{
	if (&source == &result) return; // нет нужды перемещеать самих в себя
	result = std::move(source);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "one: ";
	for (const auto& i : one)
		std::cout << i << " ";
	std::cout << std::endl;

	move_vectors(one, two);

	std::cout << "two: ";
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << std::endl;

	move_vectors(two, two);

	std::cout << "two: ";
	for (const auto& i : two)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
