#pragma once
#include <iostream>

template <class T>
struct TNode {
	T value;
	TNode* pNext;
};

template <class T>
class TStackList {
private:
	TNode<T>* pFirst;

	void copyStack(const TStackList& stack) {
		if (stack.isEmpty())
			throw "Stack can't be copied, it's empty";

		TNode<T>* sNode = stack.pFirst;

		TNode<T>* newNode = new TNode<T>;
		newNode->value = sNode->value;	newNode->pNext = nullptr;

		pFirst = newNode;

		sNode = sNode->pNext;
		TNode<T>* tmpNode = pFirst;

		while (sNode != nullptr) {
			newNode = new TNode<T>;
			newNode->value = sNode->value;	newNode->pNext = nullptr;

			tmpNode->pNext = newNode;

			sNode = sNode->pNext;
			tmpNode = tmpNode->pNext;
		}
	}

public:
	TStackList() { pFirst = nullptr; }
	TStackList(const TStackList& stack) { copyStack(stack); }
	~TStackList() { clear(); }

	bool isEmpty() const { return pFirst == nullptr; }
	bool isFull() const { return false; }

	TStackList& operator=(const TStackList& stack) {
		if (this != &stack) {
			clear();
			copyStack(stack);
		}
		return *this;
	}

	bool operator==(const TStackList& stack) const {
		TNode<T>* node = pFirst;
		TNode<T>* sNode = stack.pFirst;

		while (node != nullptr && sNode != nullptr) {
			if (node->value != sNode->value) 
				return false;

			node = node->pNext;
			sNode = sNode->pNext;
		}

		if (node != nullptr || sNode != nullptr)
			return false;

		return true;
	}

	bool operator!=(const TStackList& stack) const {
		return !(*this == stack);
	}

	void push(T value) {
		TNode<T>* newFirst = new TNode<T>;
		newFirst->value = value;
		newFirst->pNext = pFirst;

		pFirst = newFirst;
	}

	T pop() {
		if (isEmpty())
			throw "Stack is empty";

		T tmpVal = pFirst->value;

		TNode<T>* oldFirst = pFirst;
		pFirst = pFirst->pNext;
		delete oldFirst;

		return tmpVal;
	}

	T top() const {
		if (isEmpty())
			throw "Stack is empty";
		return pFirst->value;
	}

	void clear() {
		TNode<T>* node;
		while (pFirst != nullptr) {
			node = pFirst;
			pFirst = pFirst->pNext;
			delete node;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const TStackList<T>& stack) {
		TNode<T>* node = stack.pFirst;

		while (node != nullptr) {
			out << node->value << " ";
			node = node->pNext;
		}

		return out;
	}
};