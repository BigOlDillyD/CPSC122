#include <iostream>
#include "functions.h"

int main()
{

	std::cout << add(1,2) << std::endl;
	
	Date birthday = {9,20,2001};
	
	test::print(birthday.day);
	return 0;
	
}
