#include <iostream>
#include "..\Lab5\TStackList.h"

int main() {
	TStackList<int> s1;
	for (int i = 1; i <= 10; ++i)
		s1.push(3 * i - 1);

	std::cout << "Stack: " << s1 << "\n";
	std::cout << "Poped:" << s1.pop() << "\n";
	std::cout << "Poped:" << s1.pop() << "\n";
	std::cout << "Poped:" << s1.pop() << "\n";
	std::cout << "Stack: " << s1 << "\n";
	s1.push(-2);	std::cout << "Pushed:" << -2 << "\n";
	s1.push(7);		std::cout << "Pushed:" << 7 << "\n";
	std::cout << "Stack: " << s1 << "\n\n";

	TStackList<int> s2;
	s2.push(3);
	s2.push(-7);
	std::cout << "Stack1: " << s1 << "\n";
	std::cout << "Stack2: " << s2 << "\n";

	if (s1 == s2)
		std::cout << "\n(s1 == s2)\n";
	else
		std::cout << "\n(s1 != s2)\n";


	std::cout << "\ns2 = s1\n\n";
	s2 = s1;

	std::cout << "Stack1: " << s1 << "\n";
	std::cout << "Stack2: " << s2 << "\n";

	if (s1 == s2)
		std::cout << "\n(s1 == s2)\n\n";
	else
		std::cout << "\n(s1 != s2)\n\n";


	std::cout << "top:" << s1.top() << "\n";

	return 0;
}