#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if ((head == nullptr || head->next == nullptr) || k == 0)
        return head;
    Node<char>* dummy = head;
    int size = 1;
    while (dummy->next != nullptr) {
        size++;
        dummy = dummy->next;
    }
    dummy->next = head;
    k = k % size;
    int ks = size - k;
    while (ks--)
        dummy = dummy->next;
    head = dummy->next;
    dummy->next = nullptr;
    return head;
}
