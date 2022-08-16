#include "smart_array.h"
#include <iostream>
#include <sstream>
#include "ErrorEx.h"

smart_array::smart_array(int n)
	{
		if (n < 1)
		{
			std::stringstream message;

			message << "Недопустимый размер создаваемого массива!\n";
			throw ArrayException(message.str());
		}
		this->head = new int[n]();
		this->curr_size = 0;
		this->full_size = n;
	}

void smart_array::add_element(int el)
	{
		if (curr_size < full_size)
		{
			*(head + curr_size) = el;
			++curr_size;
		}
		else
		{
			std::stringstream message;

			message << "Превышен размер умного массива для добавления элементов!\n";
			throw ArrayException(message.str());
		}
	}

int smart_array::get_element(int n)
	{
		if (n <= curr_size) return *(head + n);
		else
		{
			std::stringstream message;

			message << "Недопустимый индекс при обращении к элементу массива!\n";
			throw ArrayException(message.str());
		}
	}

void smart_array::print_smart_array()
{
	for (int i = 0; i < curr_size; ++i)
		std::cout << *(head + i) << " ";
	std::cout << std::endl;
}

smart_array::~smart_array()
	{
		delete[] head;
		head = nullptr;
	}

