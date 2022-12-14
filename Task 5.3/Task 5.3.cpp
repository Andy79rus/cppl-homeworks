#include <iostream>
#include <vector>
#include <algorithm>

class Sum
{
public:
	void operator()(int n) { if (0 == n%3) sum += n; }
	int sum = 0;
};

class Count
{
public:
	void operator()(int n) {if (0 == n%3) ++count; }
	int count = 0;
};

int get_sum(std::vector<int>& v)
{
	Sum s = std::for_each(v.cbegin(), v.cend(), Sum());
	return s.sum;
}

int get_count(std::vector<int>& v)
{
	Count c = std::for_each(v.cbegin(), v.cend(), Count());
	return c.count;
}

int main()
{
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };

	std::cout << "[IN]: ";
	std::for_each(vec.cbegin(), vec.cend(), [vec](const auto i) {std::cout << i << " "; });
	std::cout << std::endl;

	std::cout << "[OUT]: get_sum() = ";
	std::cout << get_sum(vec) << std::endl;

	std::cout << "[OUT]: get_count() = ";
	std::cout << get_count(vec) << std::endl;

	return 0;
}