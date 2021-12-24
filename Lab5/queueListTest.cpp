#include <iostream>
#include "TQueueList.h"

int main() {
	TQueueList<int> q1;
	for (int i = 1; i <= 10; ++i)
		q1.push(3 * i - 1);

	std::cout << "Queue: " << q1 << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Queue: " << q1 << "\n";
	q1.push(-5);	std::cout << "Pushed:" << -5 << "\n";
	q1.push(1);		std::cout << "Pushed:" << 1 << "\n";
	std::cout << "Queue: " << q1 << "\n\n";

	TQueueList<int> q2;
	q2.push(3);
	q2.push(-7);
	std::cout << "Queue1: " << q1 << "\n";
	std::cout << "Queue2: " << q2 << "\n";

	if (q1 == q2)
		std::cout << "\n(q1 == q2)\n";
	else
		std::cout << "\n(q1 != q2)\n";


	std::cout << "\nq2 = q1\n";
	q2 = q1;

	std::cout << "Queue1: " << q1 << "\n";
	std::cout << "Queue2: " << q2 << "\n";

	if (q1 == q2)
		std::cout << "\n(q1 == q2)\n\n";
	else
		std::cout << "\n(q1 != q2)\n\n";


	std::cout << "first:" << q1.getFirst() << "\n";
	std::cout << "last:" << q1.getLast() << "\n";

	return 0;
}