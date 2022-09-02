#include <iostream>
#include <vector>
#include <set>
#include <list>

template <class T>
auto print_container(const T& container)
{
	for (const auto& i : container)
		std::cout << i << ' ';
	std::cout << std::endl;
};

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };

	print_container(test_set);
	print_container(test_list);
	print_container(test_vector);

	return 0;
}