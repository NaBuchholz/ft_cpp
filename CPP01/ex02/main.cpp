#include <iostream>
#include <string>

int main(void)
{
	std::string variable;
	variable = "HI THIS IS BRAIN";
	std::string* stringPTR;
	stringPTR = &variable;
	std::string& stringREF = variable; 

	std::cout << "The memory address of variable: " << &variable << std::endl;
	std::cout << "The memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF: " << &stringREF << std::endl;
	std::cout << "The value of variable: " << variable << std::endl;
	std::cout << "The value pointed to stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to stringREF: " << stringREF << std::endl;
	return (0);
}