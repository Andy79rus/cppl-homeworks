#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class big_integer
{
public:
	big_integer(std::string str)
	{
		this->number = str;
		this->size = static_cast<int>(str.length());
	}

	// конструктор копирования
	big_integer(const big_integer& other)
	{
		this->number = other.number;
		this->size = other.size;
	}

	//оператор присваивания
	big_integer operator=(const big_integer& other)
	{
		if (this != &other)
		{
			this->number = other.number;
			this->size = other.size;
		}
		return *this;
	}

	// конструктор перемещения
	big_integer(big_integer&& other) noexcept
	{
		this->number = other.number;
		this->size = other.size;
		other.number = "";
		other.size = 0;
	}

	//оператор перемещающего присваивания
	big_integer& operator=(big_integer&& other) noexcept
	{
		if (this != &other)
		{
			this->number = other.number;
			this->size = other.size;
			other.number = "";
			other.size = 0;
		}
		return *this;
	}

	big_integer operator+(big_integer& other)
	{
		big_integer tmp(*this);
		std::string::reverse_iterator it1 = other.number.rbegin();

		if (this->size < other.size)
		{
			tmp = other;
			it1 = this->number.rbegin();
		}
		tmp.number.insert(0, 1, '0');
		++tmp.size;
		
		std::string::reverse_iterator it2 = tmp.number.rbegin();
		while ((this->size < other.size) ? (it1 != this->number.rend()) : (it1 != other.number.rend()))
		{
			*it2 = *it2 + *it1;
			if (*it2 >= 106)
			{
				*(it2 + 1) += 1;
				*it2 -= 58;  //-'10'
			}
			else *it2 -= '0';

			++it1;
			++it2;
		}
		while (it2 != tmp.number.rend())
		{
			if (*it2 > 57)
			{
				*(it2 + 1) += 1;
				*it2 -= 10;
			}
			++it2;
		}

		if (*tmp.number.begin() == '0')
		{
			tmp.number.erase(0, 1);
			--tmp.size;
		}

		return tmp;
	}

	big_integer operator*(big_integer& other)
	{
		int new_size = this->get_size() + other.get_size();
		std::string result;
		while (new_size)
		{
			result.push_back('0');
			--new_size;
		}

		int high_p = 0;
		std::string::reverse_iterator it1 = this->number.rbegin();
		while (it1 != this->number.rend())
		{
			int this_digit = *it1 - '0';
			int i = std::distance(it1, this->number.rend()) - 1;

			std::string::reverse_iterator it2 = other.number.rbegin();
			while (it2 != other.number.rend())
			{
				int other_digit = *it2 - '0';
				int j = std::distance(it2, other.number.rend())-1;
				int result_digit = result[i + j + 1] - '0';
				int value = this_digit * other_digit + result_digit + high_p;
				int low_p = value % 10;
				result[i+j+1] = low_p + '0';
				high_p = value / 10;
				++it2;
			}

			if (high_p)
			{
				result[i] = high_p + '0';
				high_p = 0;
			}
			++it1;
		}
		big_integer tmp = big_integer(result);

		while (*tmp.number.begin() == '0')
		{
			tmp.number.erase(0, 1);
			--tmp.size;
		}

		return tmp;
	}

	big_integer operator*(int other)
	{
		big_integer tmp = big_integer(std::to_string(other));
		return *this * tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const big_integer& bi)
	{
		os << bi.number;
		return os;
	}

	int get_size()
	{
		return size;
	}

private:
	std::string number;
	int size = 0;
};