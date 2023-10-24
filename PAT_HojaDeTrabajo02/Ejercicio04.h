#pragma once
class FrontMiddleBackQueue
{
private:
	struct Node {
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size = 0;
public:
	FrontMiddleBackQueue();

	void pushFront(int value);

	void pushMiddle(int value);

	void pushBack(int value);

	int popFront();

	int popMiddle();

	int popBack();
};
