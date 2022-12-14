#pragma once
#include  <stdexcept>

template<class T>
class my_vector
{
public:
	my_vector<T>()
	{
		cells = new T[default_capacity];
		current_size = 0;
		full_capacity = default_capacity;
	}

	my_vector<T>(int n)
	{
		cells = new T[n];
		current_size = 0;
		full_capacity = n;
	}

	~my_vector()
	{
		delete[] cells;
		cells = nullptr;
	}

	// конструктор копирования
	my_vector(const my_vector& other)
	{
		this->cells = new T[other.full_capacity];
		this->full_capacity = other.full_capacity;
		this->current_size = other.current_size;
		for (int i = 0; i < this->current_size; ++i)
		{
			*(this->cells + i) = *(other.cells + i);
		}
	}

	//оператор копирующего присваивания
	my_vector& operator=(const my_vector& other)
	{
		if (this != &other)
		{
			delete[] this->cells;
			this->cells = new T[other.full_capacity];
			this->full_capacity = other.full_capacity;
			this->current_size = other.current_size;
			for (int i = 0; i < this->current_size; ++i)
			{
				*(this->cells + i) = *(other.cells + i);
			}
		}
		return *this;
	}

	// конструктор перемещения
	my_vector(my_vector&& other) noexcept
	{
		this->cells = other.cells;
		this->full_capacity = other.full_capacity;
		this->current_size = other.current_size;

		other.full_capacity = 0;
		other.current_size = 0;
		other.cells = nullptr;
	}

	//оператор перемещающего присваивания
	my_vector& operator=(my_vector&& other) noexcept
	{
		if (this != &other)
		{
			delete[] this->cells;
			this->cells = other.cells;
			this->full_capacity = other.full_capacity;
			this->current_size = other.current_size;

			other.full_capacity = 0;
			other.current_size = 0;
			other.cells = nullptr;
		}
		return *this;
	}

	T& at(int idx) const
	{
		if (idx>=0 && idx<current_size) return cells[idx];
		throw std::out_of_range("Некорректный индекс обращения к элементу вектора my_vector");
	}

	void push_back(T val)
	{
		if (current_size >= full_capacity)
			resize_up();
		cells[current_size] = val;
		++current_size;
	}

	int size()
	{
		return current_size;
	}

	int capacity()
	{
		return full_capacity - current_size;
	}

private:
	void resize_up()
	{
		int new_capacity = full_capacity * 3/2;
		T* tmp = new T[new_capacity];
		full_capacity = new_capacity;
		for (int i = 0; i < this->current_size; ++i)
		{
			*(tmp + i) = *(this->cells + i);
		}
		T* p = tmp;
		tmp = cells;
		cells = p;
		delete[] tmp;
	}

	const int default_capacity = 10;
	T* cells = nullptr;
	int current_size = 0;
	int full_capacity = 0;
};