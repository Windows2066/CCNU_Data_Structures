#include <bits/stdc++.h>

#ifndef CIRCULARQUEUE_STL_CPP
#define CIRCULARQUEUE_STL_CPP

typedef struct
{
    std::queue<int> q;
} Queue;

void InitQueue(Queue &Q)
{
    while (!Q.q.empty())
        Q.q.pop();
}

bool DestroyQueue(Queue &Q)
{
    InitQueue(Q);
    return true;
}

bool ClearQueue(Queue &Q)
{
    InitQueue(Q);
    return true;
}

bool QueueEmpty(Queue Q)
{
    return Q.q.empty();
}

bool QueueFull(Queue Q)
{
    return false;
}

int QueueLength(Queue Q)
{
    return Q.q.size();
}

bool GetHead(Queue Q, int &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.q.front();
    return true;
}

bool EnQueue(Queue &Q, int e)
{
    Q.q.push(e);
    return true;
}

bool DeQueue(Queue &Q, int &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.q.front();
    Q.q.pop();
    return true;
}

bool QueueTraverse(Queue Q)
{
    // if (QueueEmpty(Q))
    // {
    //     std::cout << "Queue is empty!" << std::endl;
    //     return false;
    // }
    std::cout << "便道上目前有" << QueueLength(Q) << "辆车：\n";
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    std::queue<int> q = Q.q;
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    return true;
}

#endif // CIRCULARQUEUE_STL_CPP