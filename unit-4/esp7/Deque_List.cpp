#include <bits/stdc++.h>

#ifndef DEQUE_LIST_CPP
#define DEQUE_LIST_CPP

typedef struct Node
{
    int data;
    Node *prev;
    Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int length;
} Deque;

void InitDeque(Deque &Q)
{
    Q.head = nullptr;
    Q.tail = nullptr;
    Q.length = 0;
}

bool DestroyDeque(Deque &Q)
{
    while (Q.head != nullptr)
    {
        Node *temp = Q.head;
        Q.head = Q.head->next;
        delete temp;
    }
    Q.tail = nullptr;
    Q.length = 0;
    return true;
}

bool ClearDeque(Deque &Q)
{
    DestroyDeque(Q);
    return true;
}

bool DequeEmpty(Deque Q)
{
    return Q.length == 0;
}

bool DequeFull(Deque Q)
{
    return false;
}

int DequeLength(Deque Q)
{
    return Q.length;
}

bool GetHead(Deque Q, int &e)
{
    if (DequeEmpty(Q))
        return false;
    e = Q.head->data;
    return true;
}

bool HeadEnDeque(Deque &Q, int e)
{
    Node *newNode = new Node{e, nullptr, Q.head};
    if (DequeEmpty(Q))
    {
        Q.head = Q.tail = newNode;
    }
    else
    {
        Q.head->prev = newNode;
        Q.head = newNode;
    }
    Q.length++;
    return true;
}

bool HeadDeDeque(Deque &Q, int &e)
{
    if (DequeEmpty(Q))
        return false;
    Node *temp = Q.head;
    e = Q.head->data;
    Q.head = Q.head->next;
    if (Q.head != nullptr)
        Q.head->prev = nullptr;
    else
        Q.tail = nullptr;
    delete temp;
    Q.length--;
    return true;
}

bool GetTail(Deque Q, int &e)
{
    if (DequeEmpty(Q))
        return false;
    e = Q.tail->data;
    return true;
}

bool TailEnDeque(Deque &Q, int e)
{
    Node *newNode = new Node{e, Q.tail, nullptr};
    if (DequeEmpty(Q))
    {
        Q.head = Q.tail = newNode;
    }
    else
    {
        Q.tail->next = newNode;
        Q.tail = newNode;
    }
    Q.length++;
    return true;
}

bool TailDeDeque(Deque &Q, int &e)
{
    if (DequeEmpty(Q))
        return false;
    Node *temp = Q.tail;
    e = Q.tail->data;
    Q.tail = Q.tail->prev;
    if (Q.tail != nullptr)
        Q.tail->next = nullptr;
    else
        Q.head = nullptr;
    delete temp;
    Q.length--;
    return true;
}

bool DequeTraverse(Deque Q)
{
    if (DequeEmpty(Q))
    {
        std::cout << "Deque is empty!" << std::endl;
        return false;
    }
    Node *current = Q.head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return true;
}

#endif // DEQUE_LIST_CPP