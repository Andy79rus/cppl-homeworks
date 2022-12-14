#include "my_vector.h"
#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	my_vector<int> vec1(8);

	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;

	vec1.push_back(1);
	vec1.push_back(2);

	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;

	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(6);
	vec1.push_back(7);
	vec1.push_back(8);
	vec1.push_back(9);
	vec1.push_back(10);

	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;

	vec1.push_back(11);

	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "vec1.at(5)" << std::endl;
	std::cout << vec1.at(5) << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << vec1.at(25) << std::endl;
	}
	catch(const std::out_of_range& ex)
	{
		std::cout << "vec1.at(25)" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	std::cout << vec1.at(3) << std::endl;
	vec1.at(3) = 30;
	std::cout << vec1.at(3) << std::endl;
	std::cout << std::endl;

	try
	{
		vec1.at(30) = 100;
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "vec1.at(30) = 100;" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	my_vector<std::string> vec2(5);
	vec2.push_back("one");
	vec2.push_back("two");
	vec2.push_back("three");

	my_vector<std::string> vec3(vec2);

	std::cout << "vec3: ";
	for (int i = 0; i < vec3.size(); ++i)
		std::cout << vec3.at(i) << " ";
	std::cout << std::endl;

	vec3.push_back("five");
	vec3.at(2) = "four";

	std::cout << "vec3: ";
	for (int i = 0; i < vec3.size(); ++i)
		std::cout << vec3.at(i) << " ";
	std::cout << std::endl;

	my_vector<std::string> vec4(std::move(vec3));

	std::cout << "vec3: ";
	for (int i = 0; i < vec3.size(); ++i)
		std::cout << vec3.at(i) << " ";
	std::cout << std::endl;

	std::cout << "vec4: ";
	for (int i = 0; i < vec4.size(); ++i)
		std::cout << vec4.at(i) << " ";
	std::cout << std::endl;

	vec3 = std::move(vec4);

	std::cout << "vec3: ";
	for (int i = 0; i < vec3.size(); ++i)
		std::cout << vec3.at(i) << " ";
	std::cout << std::endl;

	std::cout << "vec4: ";
	for (int i = 0; i < vec4.size(); ++i)
		std::cout << vec4.at(i) << " ";
	std::cout << std::endl;

	return 0;
}