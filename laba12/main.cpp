#include <iostream>
#include "Rational.h"

int main()
{
		char operation[2];
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
		std::cout << "Result: " << res;
}
