#include <bits/stdc++.h>
using namespace std;
#include "CircularQueue_SqList.cpp"
// #include "CircularQueue_stl.cpp"

int main()
{
    Queue Q;
    InitQueue(Q);

    cout << "Queue is empty: " << (QueueEmpty(Q) ? "Yes" : "No") << endl;

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    cout << "After enqueuing 1, 2, 3:" << endl;
    QueueTraverse(Q);

    int head;
    if (GetHead(Q, head))
        cout << "Head element: " << head << endl;
    else
        cout << "Failed to get head element." << endl;

    int dequeuedElement;
    if (DeQueue(Q, dequeuedElement))
        cout << "Dequeued element: " << dequeuedElement << endl;
    else
        cout << "Failed to dequeue element." << endl;

    cout << "After dequeuing one element:" << endl;
    QueueTraverse(Q);

    cout << "Queue length: " << QueueLength(Q) << endl;

    ClearQueue(Q);
    cout << "After clearing the queue:" << endl;
    QueueTraverse(Q);

    for (int i = 1; i <= 109; i++)
        EnQueue(Q, i);
    cout << "Queue is full: " << (QueueFull(Q) ? "Yes" : "No") << endl;

    DestroyQueue(Q);
    cout << "After destroying the queue:" << endl;
    cout << "Queue is empty: " << (QueueEmpty(Q) ? "Yes" : "No") << endl;
    return 0;
}