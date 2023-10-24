#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    Node<int>* resultado = new Node<int>{ 0 };
    Node<int>* dummy = resultado;
    int agg = 0;
    while (l1 || l2 || agg) {
        agg = (l1 ? l1->value : 0) + (l2 ? l2->value : 0) + agg;
        dummy->next = new Node<int>{ agg % 10 };
        agg /= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        dummy = dummy->next;
    }

    return resultado->next;
}
