#pragma once
#include <iostream>
namespace test
{
	template<typename T>
	void print(T x)
	{
		std::cout << x << std::endl;
	}
}

struct Date
{
	int day;
	int month;
	int year;


};

int add(int, int);
