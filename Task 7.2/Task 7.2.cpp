#include <iostream>
#include <unordered_set>
#include <algorithm>

void print_result(const std::vector<int>& vec)
{
	for (const auto& value : vec) {
		std::cout << value << std::endl;
	}
}

bool compare(int n1, int n2) {
	return n1 > n2;
}

int main()
{
	std::cout << "[IN]: " << std::endl;
	int n = 0;
	std::cin >> n;
	
	std::unordered_set<int> nums;

	int tmp = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		nums.insert(tmp);
	}

	std::vector<int> result(nums.cbegin(), nums.cend());
	std::sort(result.begin(), result.end(), compare);

	std::cout << "[OUT]: " << std::endl;
	print_result(result);

	return 0;
}