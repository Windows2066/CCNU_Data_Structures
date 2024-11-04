#include <bits/stdc++.h>
using namespace std;
// #include "Deque_stl.cpp"
#include "Deque_List.cpp"

int main()
{
    Deque Q;
    InitDeque(Q);

    cout << "Deque is empty: " << (DequeEmpty(Q) ? "Yes" : "No") << endl;

    HeadEnDeque(Q, 1);
    HeadEnDeque(Q, 2);
    HeadEnDeque(Q, 3);
    cout << "After enqueuing 1, 2, 3 at the front:" << endl;
    DequeTraverse(Q);

    TailEnDeque(Q, 4);
    TailEnDeque(Q, 5);
    cout << "After enqueuing 4, 5 at the rear:" << endl;
    DequeTraverse(Q);

    cout << "Deque's length:" << DequeLength(Q) << endl;

    int head;
    if (GetHead(Q, head))
        cout << "Head element: " << head << endl;
    else
        cout << "Failed to get head element." << endl;

    int tail;
    if (GetTail(Q, tail))
        cout << "Tail element: " << tail << endl;
    else
        cout << "Failed to get tail element." << endl;

    int dequeuedElement;
    if (HeadDeDeque(Q, dequeuedElement))
        cout << "Dequeued element from front: " << dequeuedElement << endl;
    else
        cout << "Failed to dequeue element from front." << endl;

    cout << "After dequeuing one element from front:" << endl;
    DequeTraverse(Q);

    if (TailDeDeque(Q, dequeuedElement))
        cout << "Dequeued element from rear: " << dequeuedElement << endl;
    else
        cout << "Failed to dequeue element from rear." << endl;

    cout << "After dequeuing one element from rear:" << endl;
    DequeTraverse(Q);

    ClearDeque(Q);
    cout << "After clearing the deque:" << endl;
    DequeTraverse(Q);

    DestroyDeque(Q);
    cout << "After destroying the deque:" << endl;
    cout << "Deque is empty: " << (DequeEmpty(Q) ? "Yes" : "No") << endl;
}