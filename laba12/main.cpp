#include <iostream>
#include "Rational.h"

int main()
{
	try {
		char operation[3];
		Rational a, b, res;
		std::cout << "Input first frection: ";
		std::cin >> a;
		std::cout << "Input second frection: ";
		std::cin >> b;
		std::cout << "Input operation: ";
		std::cin >> operation;
		if (operation[0] == '+') res = a + b;
		if (operation[0] == '-') res = a - b;
		if (operation[0] == '*') res = a * b;
		if (operation[0] == '/') res = a / b;
		if (operation[0] == '+' && operation[1] == '=');
		std::cout << "Result: " << res;
	}
	catch (const char* Error) {
		std::cout << Error << std::endl;
	}
}
