#include <bits/stdc++.h>

#ifndef CIRCULARQUEUE_SQLIST_CPP
#define CIRCULARQUEUE_SQLIST_CPP

constexpr int QUEUE_INIT_SIZE = 100;
constexpr int QUEUE_INCREMENT = 10;

typedef struct
{
    int *data;
    int front, rear;
    int queuesize, incrementsize;
} Queue;

void InitQueue(Queue &Q)
{
    Q.queuesize = QUEUE_INIT_SIZE;
    Q.incrementsize = QUEUE_INCREMENT;
    Q.data = new int[Q.queuesize];
    Q.front = Q.rear = 0;
}

bool DestroyQueue(Queue &Q)
{
    if (Q.data)
    {
        delete[] Q.data;
        Q.data = nullptr;
        Q.front = Q.rear = 0;
        return true;
    }
    return false;
}

bool ClearQueue(Queue &Q)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    Q.front = Q.rear = 0;
    return true;
}

bool QueueEmpty(Queue Q)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    return Q.front == Q.rear;
}

bool QueueFull(Queue Q)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    return (Q.rear + 1) % Q.queuesize == Q.front;
}

int QueueLength(Queue Q)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return -1;
    }
    return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

bool GetHead(Queue Q, int &e)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    if (QueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    return true;
}

bool EnQueue(Queue &Q, int e)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    if ((Q.rear + 1) % Q.queuesize == Q.front)
    {
        // 队列满，扩展队列
        int *newData = new int[Q.queuesize + Q.incrementsize];
        int i = 0;
        while (Q.front != Q.rear)
        {
            newData[i++] = Q.data[Q.front];
            Q.front = (Q.front + 1) % Q.queuesize;
        }
        delete[] Q.data;
        Q.data = newData;
        Q.front = 0;
        Q.rear = i;
        Q.queuesize += Q.incrementsize;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
    return true;
}

bool DeQueue(Queue &Q, int &e)
{
    if (!Q.data)
    {
        std::cerr << "Queue is not initialized!" << std::endl;
        return false;
    }
    if (QueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;
    return true;
}

bool QueueTraverse(Queue Q)
{
    // if (!Q.data)
    // {
    //     std::cerr << "Queue is not initialized!" << std::endl;
    //     return false;
    // }
    // if (QueueEmpty(Q))
    // {
    //     std::cout << "Queue is empty!" << std::endl;
    //     return false;
    // }
    std::cout << "便道上目前有" << QueueLength(Q) << "辆车：\n";
    int i = Q.front;
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    while (i != Q.rear)
    {
        std::cout << Q.data[i] << " \n"[i == Q.rear - 1];
        i = (i + 1) % Q.queuesize;
    }
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    return true;
}

#endif // CIRCULARQUEUE_SQLIST_CPP