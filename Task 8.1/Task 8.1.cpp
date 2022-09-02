#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::vector<int> vec2 = { 1, 8, 1, 6, 2, 2, 3, 5, 5, 5, 2, 4, 1, 6, 2, 3, 10, 6, 2, 5, 6, 3, 7 };

	auto print = [](const std::vector<int>& v) {
		for (const auto& i : v)
			std::cout << i << ' ';
		std::cout << std::endl;
	};

	std::cout << "[IN]: ";
	print(vec);

	std::sort(vec.begin(), vec.end());
	auto not_unique = std::unique(vec.begin(), vec.end());
	vec.erase(not_unique, vec.end());

	std::cout << "[OUT]: ";
	print(vec);

	std::cout << std::endl;

	std::cout << "[IN]: ";
	print(vec2);

	std::sort(vec2.begin(), vec2.end());
	not_unique = std::unique(vec2.begin(), vec2.end());
	vec2.erase(not_unique, vec2.end());

	std::cout << "[OUT]: ";
	print(vec2);

	return 0;
}