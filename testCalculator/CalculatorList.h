#pragma once
#include "..\Lab5\TStackList.h"
#include <string>
#include <cmath>

class Calculator {
private:
	std::string expr;
	std::string postfix;
	TStackList<char> stackChar;
	TStackList<double> stackDouble;


	int prior(char op) {
		switch (op) {
		case '(': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		}
		return 0;
	}


public:
	Calculator() {}
	~Calculator() {}

	Calculator(const Calculator& calc) {
		expr = calc.expr;
		postfix = calc.postfix;
	}

	void setExpr(std::string _expr) { expr = _expr; }
	std::string getExpr() const { return expr; }
	std::string getPostfix() const { return postfix; }

	Calculator& operator=(const Calculator& calc) {
		expr = calc.expr;
		postfix = calc.postfix;
		return *this;
	}

	bool checkExpr() {
		for (size_t i = 0; i < expr.length(); i++) {
			if (expr[i] == '(')
				stackChar.push(expr[i]);

			else if (expr[i] == ')') {
				if (stackChar.isEmpty()) 
					return false;

				else stackChar.pop();
			}
		}

		return stackChar.isEmpty();
	}

	void toPostfix() {
		std::string infix = "(" + expr + ")";
		postfix = "";
		stackChar.clear();

		for (size_t i = 0; i < infix.size(); i++) {
			if (isdigit(infix[i])) {
				postfix += infix[i];
				postfix += " ";
			}
			else if (infix[i] == '(') {
				stackChar.push(infix[i]);
			}
			else if (infix[i] == ')') {
				while (stackChar.top() != '(') {
					postfix += stackChar.pop();
					postfix += " ";
				}
				stackChar.pop();
			}
			else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^')) {
				while (prior(infix[i]) <= prior(stackChar.top())) {
					postfix += stackChar.pop();
					postfix += " ";
				}
				stackChar.push(infix[i]);
			}
		}

		if (!postfix.empty())
			postfix.pop_back();
	}

	double calcPostfix() {
		for (size_t i = 0; i < postfix.length(); i++) {
			if (postfix[i] >= '0' && postfix[i] <= '9') {
				stackDouble.push(std::stod(&postfix[i]));	// string to double
			}
			else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
				if (stackDouble.isEmpty())
					throw "Too many operators";
				double second = stackDouble.pop();

				if (stackDouble.isEmpty())
					throw "Too many operators";
				double first = stackDouble.pop();

				switch (postfix[i]) {
				case '+':
					stackDouble.push(first + second);
					break;
				case '-':
					stackDouble.push(first - second);
					break;
				case '*':
					stackDouble.push(first * second);
					break;
				case '/':
					stackDouble.push(first / second);
					break;
				case '^':
					stackDouble.push(pow(first, second));
					break;
				}
			}
		}

		if (stackDouble.isEmpty())
			throw "Not enough operands";

		double result = stackDouble.pop();

		if (!stackDouble.isEmpty())
			throw "Too many operands";

		return result;
	}

	double modernCalc() {
		std::string infix = "(" + expr + ")";
		stackChar.clear();
		stackDouble.clear();

		for (size_t i = 0; i < infix.size(); i++) {
			if (infix[i] == '(')
				stackChar.push(infix[i]);

			else if (isdigit(infix[i])) {
				size_t idx;
				double tmp = std::stod(&infix[i], &idx);
				stackDouble.push(tmp);
				i += idx - 1;
			}

			else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^')) {
				while (prior(infix[i]) <= prior(stackChar.top())) {
					if (stackDouble.isEmpty())
						throw "Too many operators";
					double second = stackDouble.pop();

					if (stackDouble.isEmpty())
						throw "Too many operators";
					double first = stackDouble.pop();

					char op = stackChar.pop();
					switch (op) {
					case '+':
						stackDouble.push(first + second);
						break;
					case '-':
						stackDouble.push(first - second);
						break;
					case '*':
						stackDouble.push(first * second);
						break;
					case '/':
						stackDouble.push(first / second);
						break;
					case '^':
						stackDouble.push(pow(first, second));
						break;
					}
				}
				stackChar.push(infix[i]);
			}
			else if (infix[i] == ')') {
				while (stackChar.top() != '(') {
					if (stackDouble.isEmpty())
						throw "Too many operators";
					double second = stackDouble.pop();

					if (stackDouble.isEmpty())
						throw "Too many operators";
					double first = stackDouble.pop();

					char op = stackChar.pop();
					switch (op) {
					case '+':
						stackDouble.push(first + second);
						break;
					case '-':
						stackDouble.push(first - second);
						break;
					case '*':
						stackDouble.push(first * second);
						break;
					case '/':
						stackDouble.push(first / second);
						break;
					case '^':
						stackDouble.push(pow(first, second));
						break;
					}
				}
				stackChar.pop();
			}
		}

		if (stackDouble.isEmpty())
			throw "Not enough operands";

		double result = stackDouble.pop();

		if (!stackDouble.isEmpty())
			throw "Too many operands";

		return result;
	}
};