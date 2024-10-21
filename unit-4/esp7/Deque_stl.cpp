#include <bits/stdc++.h>

#ifndef DEQUE_STL_CPP
#define DEQUE_STL_CPP

typedef struct
{
    std::deque<int> q;
} Deque;

void InitDeque(Deque &Q)
{
    Q.q.clear();
}

bool DestroyDeque(Deque &Q)
{
    InitDeque(Q);
    return true;
}

bool ClearDeque(Deque &Q)
{
    InitDeque(Q);
    return true;
}

bool DequeEmpty(Deque Q)
{
    return Q.q.empty();
}

bool DequeFull(Deque Q)
{
    return false;
}

int DequeLength(Deque Q)
{
    return Q.q.size();
}

bool GetHead(Deque Q, int &e)
{
    if (DequeEmpty(Q))
    {
        return false;
    }
    e = Q.q.front();
    return true;
}

bool HeadEnDeque(Deque &Q, int e)
{
    Q.q.push_front(e);
    return true;
}

bool HeadDeDeque(Deque &Q, int &e)
{
    if (DequeEmpty(Q))
    {
        return false;
    }
    e = Q.q.front();
    Q.q.pop_front();
    return true;
}

bool GetTail(Deque Q, int &e)
{
    if (DequeEmpty(Q))
    {
        return false;
    }
    e = Q.q.back();
    return true;
}

bool TailEnDeque(Deque &Q, int e)
{
    Q.q.push_back(e);
    return true;
}

bool TailDeDeque(Deque &Q, int &e)
{
    if (DequeEmpty(Q))
    {
        return false;
    }
    e = Q.q.back();
    Q.q.pop_back();
    return true;
}

bool DequeTraverse(Deque Q)
{
    if (DequeEmpty(Q))
    {
        std::cout << "Deque is empty!" << std::endl;
        return false;
    }
    std::deque<int> q = Q.q;
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop_front();
    }
    std::cout << std::endl;
    return true;
}

#endif // DEQUE_STL_CPP