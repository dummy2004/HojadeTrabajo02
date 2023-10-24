#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
    head = tail = nullptr;
    size = 0;
}

void FrontMiddleBackQueue::pushFront(int value)
{
    Node* temp = new Node{ value };
    if (size == 0) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }

    size++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
    Node* temp = new Node{ value };
    if (size == 0) {
        head = tail = temp;
    }
    else if (size == 1) {
        temp->next = head;
        head = temp;
    }
    else {
        Node* demo = head;
        int n = size / 2;
        int i = 0;
        while (i != (n - 1)) {
            demo = demo->next;
            i++;
        }
        temp->next = demo->next;
        demo->next = temp;
    }

    size++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
    Node* temp = new Node{ value };
    if (size == 0) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

int FrontMiddleBackQueue::popFront()
{
    if (size == 0) {
        return -1;
    }
    int value = head->val;
    head = head->next;
    if (size == 1) {
        tail = head;
    }
    size--;
    return value;
}

int FrontMiddleBackQueue::popMiddle()
{
    int value = 0;
    if (size == 0) {
        return -1;
    }
    else if (size == 1) {
        value = head->val;
        head = head->next;
        tail = head;
    }
    else if (size == 2) {
        value = head->val;
        head = head->next;
    }
    else if (size % 2 == 1) {
        Node* demo = head;
        int n = size / 2;
        int i = 0;
        while (i != (n - 1)) {
            demo = demo->next;
            i++;
        }
        value = demo->next->val;
        demo->next = demo->next->next;
    }
    else if (size % 2 == 0) {
        Node* demo = head;
        int n = (size / 2) - 1;
        int i = 0;
        while (i != (n - 1)) {
            demo = demo->next;
            i++;
        }
        value = demo->next->val;
        demo->next = demo->next->next;
    }
    size--;
    return value;
}

int FrontMiddleBackQueue::popBack()
{
    int value = 0;
    if (size == 0) {
        return -1;
    }
    else if (size == 1) {
        value = tail->val;
        tail = tail->next;
        head = tail;
    }
    else {
        Node* demo = head;
        while (demo->next != tail) {
            demo = demo->next;
        }
        value = tail->val;
        demo->next = tail->next;
        tail = demo;
    }
    size--;
    return value;
}