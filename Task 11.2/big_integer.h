#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class big_integer
{
public:
	big_integer(const std::string& str) : number(str), capacity(static_cast<int>(number.length()))  //необходимо для задачи проекта Эйлера, где применяем std::vector
	{}

	big_integer(std::string&& str) : number(std::move(str)), capacity(static_cast<int>(number.length()))
	{}

	// конструктор копирования
	big_integer(const big_integer& other) : number(other.number), capacity(static_cast<int>(number.length()))
	{}

	//оператор присваивания
	big_integer& operator=(const big_integer& other)
	{
		if (this != &other)
		{
			this->number = other.number;
			this->capacity = other.capacity;
		}
		return *this;
	}

	// конструктор перемещения
	big_integer(big_integer&& other) noexcept
	{
		number = std::move(other.number);
		capacity = other.capacity;
	}

	//оператор перемещающего присваивания
	big_integer& operator=(big_integer&& other) noexcept
	{
		if (this != &other)
		{
			number = std::move(other.number);
			capacity = other.capacity;
		}
		return *this;
	}

	big_integer operator+(const big_integer& other)
	{
		big_integer tmp(*this);
		std::string::const_reverse_iterator it1 = other.number.rbegin();

		if (this->capacity < other.capacity)
		{
			tmp = other;
			it1 = this->number.rbegin();
		}
		tmp.number.insert(0, 1, '0');
		++tmp.capacity;
		
		std::string::reverse_iterator it2 = tmp.number.rbegin();
		while ((this->capacity < other.capacity) ? (it1 != this->number.rend()) : (it1 != other.number.rend()))
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
			--tmp.capacity;
		}

		return tmp;
	}

	big_integer operator*(const big_integer& other) const
	{
		int new_capacity = this->get_capacity() + other.get_capacity();
		std::string result;
		while (new_capacity)
		{
			result.push_back('0');
			--new_capacity;
		}

		int high_p = 0;
		std::string::const_reverse_iterator it1 = this->number.rbegin();
		while (it1 != this->number.rend())
		{
			int this_digit = *it1 - '0';
			__int64 i = std::distance(it1, this->number.rend()) - 1;

			std::string::const_reverse_iterator it2 = other.number.rbegin();
			while (it2 != other.number.rend())
			{
				int other_digit = *it2 - '0';
				__int64 j = std::distance(it2, other.number.rend())-1;
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
		big_integer tmp = big_integer(std::move(result));

		while ((*tmp.number.begin() == '0') && (tmp.capacity > 1))
		{
			tmp.number.erase(0, 1);
			--tmp.capacity;
		}

		return tmp;
	}

	big_integer operator*(int other) const
	{
		big_integer tmp = big_integer(std::to_string(other));
		return *this * tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const big_integer& bi)
	{
		os << bi.number;
		return os;
	}

	int get_capacity() const
	{
		return capacity;
	}

private:
	std::string number;
	int capacity = 0;
};