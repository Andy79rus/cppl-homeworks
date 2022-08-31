#include <iostream>
#include <unordered_map>
#include <algorithm>

void print_result(const std::vector<std::pair<char, int>>& vec)
{
    //ISO C++17 Standard
	for (const auto& [key, value] : vec) {
		std::cout << key << ": " << value << std::endl;
	}
}

bool compare(std::pair<char, int> p1, std::pair<char, int> p2) {
	return p1.second > p2.second;
}

int main()
{
	std::string test = "Hello world!!";
	//std::string test = "And when you gaze long into an abyss, the abyss also gazes into you.";
	std::cout << "[IN]: " << test << std::endl;

	std::unordered_map<char, int> char_count;

	std::for_each(test.cbegin(), test.cend(), [&char_count](auto const& c)
		{
			std::pair<std::unordered_map<char, int>::iterator, bool> it;
			it = char_count.insert(std::pair<char, int>(c, 1));
			if (it.second == false)	++(it.first->second);
		});

	std::vector<std::pair<char, int>> result(char_count.cbegin(), char_count.cend());
	std::sort(result.begin(), result.end(), compare);

	std::cout << "[OUT]: " << std::endl;
	print_result(result);

	return 0;
}
