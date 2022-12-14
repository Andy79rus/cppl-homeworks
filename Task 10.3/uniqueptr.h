#pragma once

template <class T>
class uniqueptr
{
public:
	uniqueptr<T>(T* ptr)
	{
		this->u_ptr = ptr;
	}

	//оператор копирующего присваивания
	uniqueptr<T>& operator=(const uniqueptr& other) = delete;

	// конструктор копирования
	uniqueptr<T>(const uniqueptr& other) = delete;

	// конструктор перемещения
	uniqueptr<T>(uniqueptr&& other) noexcept
	{
		this->u_ptr = other.u_ptr;
		other.u_ptr = nullptr;
	}

	//оператор перемещающего присваивания
	uniqueptr<T>& operator=(uniqueptr&& other) noexcept
	{
		if (this != &other)
		{
			delete this->u_ptr;
			this->u_ptr = other.u_ptr;
			other.u_ptr = nullptr;
		}
		return *this;
	}

	~uniqueptr<T>()
	{
		u_ptr = nullptr;
	}

	T* release()
	{
		T* tmp = u_ptr;
		u_ptr = nullptr;
		return tmp;
	}

	//оператор разыменовывания указателя
	T& operator*() const
	{
		return *u_ptr;
	}

private:
	T* u_ptr = nullptr;
};