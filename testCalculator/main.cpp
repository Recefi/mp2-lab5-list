#include <iostream>
#include <string>
#include "CalculatorList.h"


int main() {
	Calculator calc;
	std::string input;

	std::cout << "Enter the expression: ";
	std::getline(std::cin, input);
	calc.setExpr(input);
	std::cout << "The brackets in " << calc.getExpr();

	if (calc.checkExpr())
		std::cout << " are correct\n";
	else {
		std::cout << " aren't correct\n";
		return -1;
	}

	std::cout << "\n\tThe first type of calculator (digits only):\n\n";
	try {
		calc.toPostfix();
		std::cout << "Postfix: "; 
		std::cout << calc.getPostfix() << "\n";
		std::cout << "Result: ";
		std::cout << calc.calcPostfix() << "\n\n";
	}
	catch (...) {
		std::cout << "\nError\n\n";
	}


	std::cout << "\n\tThe second type of calculator:\n\n";
	try {
		std::cout << "Result: ";
		std::cout << calc.modernCalc() << "\n\n";
	}
	catch (const char* exception) {
		std::cout << "\nError: " << exception << "\n\n";
	}
	catch (...) {
		std::cout << "\nUnknown error\n\n";
	}

	return 0;
}