#include "Table.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size1 = 5;
	int size2 = 3;

	Table<int> newTable(size1,size2);

	newTable[0][0] = 4;
	newTable[1][2] = 5;

	std::cout << newTable[0][0] << std::endl;
	std::cout << newTable[1][2] << std::endl;

	std::cout << std::endl;
	std::cout << newTable.Size() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			std::cout << newTable[i][j] << "\t";
		std::cout << std::endl;
	}

	Table<int> nt(newTable);

	std::cout << std::endl;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			std::cout << nt[i][j] << "\t";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	size1 = 4;
	size2 = 2;

	Table<int> newTable2(size1, size2);

	newTable2[0][1] = 3;
	newTable2[1][1] = 2;
	newTable2[3][0] = 10;

	try
	{
		std::cout << "newTable2[8][1] = 4;" << std::endl;
		newTable2[8][1] = 4;
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			std::cout << newTable2[i][j] << "\t";
		std::cout << std::endl;
	}

	nt = newTable2;

	std::cout << std::endl;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			std::cout << nt[i][j] << "\t";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	const Table<int> newTable3(nt);
	
	std::cout << newTable3[1][1] << std::endl;
	std::cout << newTable3[3][0] << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << "std::cout << newTable3[10][10] << std::endl;" << std::endl;
		std::cout << newTable3[10][10] << std::endl;
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}