#pragma once
#include <iostream>

template <class T>
struct TNode {
	T value;
	TNode* pNext;
};

template <class T>
class TQueueList {
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;

	void copyQueue(const TQueueList& queue) {
		if (queue.isEmpty())
			throw "Queue can't be copied, it's empty";

		TNode<T>* qNode = queue.pFirst;

		TNode<T>* newNode = new TNode<T>;
		newNode->value = qNode->value;	newNode->pNext = nullptr;

		pFirst = newNode;

		qNode = qNode->pNext;
		TNode<T>* tmpNode = pFirst;

		while (qNode != nullptr) {
			newNode = new TNode<T>;
			newNode->value = qNode->value;	newNode->pNext = nullptr;

			tmpNode->pNext = newNode;

			qNode = qNode->pNext;
			tmpNode = tmpNode->pNext;
		}
		pLast = tmpNode;
	}

public:
	TQueueList() { pFirst = pLast = nullptr; }
	TQueueList(const TQueueList& queue) { copyQueue(queue); }
	~TQueueList() { clear(); }

	bool isEmpty() const { return pFirst == nullptr; }
	bool isFull() const { return false; }

	TQueueList& operator=(const TQueueList& queue) {
		if (this != &queue) {
			clear();
			copyQueue(queue);
		}
		return *this;
	}

	bool operator==(const TQueueList& queue) const {
		TNode<T>* node = pFirst;
		TNode<T>* qNode = queue.pFirst;

		while (node != nullptr && qNode != nullptr) {
			if (node->value != qNode->value)
				return false;

			node = node->pNext;
			qNode = qNode->pNext;
		}

		if (node != nullptr || qNode != nullptr)
			return false;

		return true;
	}

	bool operator!=(const TQueueList& queue) const {
		return !(*this == queue);
	}

	void push(T value) {
		TNode<T>* newNode = new TNode<T>;
		newNode->value = value;
		newNode->pNext = nullptr;

		if (pLast != nullptr)
			pLast->pNext = newNode;
		else
			pFirst = newNode;

		pLast = newNode;
	}

	T pop() {
		if (isEmpty())
			throw "Queue is empty";

		T tmpVal = pFirst->value;

		TNode<T>* oldFirst = pFirst;
		pFirst = oldFirst->pNext;
		delete oldFirst;

		if (pFirst == nullptr)
			pLast = nullptr;

		return tmpVal;
	}

	void clear() {
		TNode<T>* node;
		while (pFirst != nullptr) {
			node = pFirst;
			pFirst = pFirst->pNext;
			delete node;
		}
		pLast = nullptr;
	}

	T getFirst() const {
		if (isEmpty())
			throw "Queue is empty";
		return pFirst->value;
	}

	T getLast() const {
		if (isEmpty())
			throw "Queue is empty";
		return pLast->value;
	}

	friend std::ostream& operator<<(std::ostream& out, const TQueueList<T>& queue) {
		TNode<T>* node = queue.pFirst;

		while (node != nullptr) {
			out << node->value << " ";
			node = node->pNext;
		}

		return out;
	}
};