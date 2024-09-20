#ifdef list_ptr_h
#include "list_ptr.cpp"

LinkList FindFirstCommonNode(LinkList L1, LinkList L2)
{
    int len1 = ListLength(L1);
    int len2 = ListLength(L2);

    LinkList longer = L1;
    LinkList shorter = L2;
    int diff = len1 - len2;

    if (len2 > len1)
    {
        longer = L2;
        shorter = L1;
        diff = len2 - len1;
    }

    for (int i = 0; i < diff; ++i)
    {
        longer = longer->next;
    }

    while (longer != nullptr && shorter != nullptr)
    {
        if (longer == shorter)
        {
            return longer;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return nullptr;
}

LinkList MergeSortedLists(LinkList L1, LinkList L2)
{
    if (L1 == nullptr)
        return L2;
    if (L2 == nullptr)
        return L1;

    LinkList mergedHead = nullptr;
    LinkList mergedTail = nullptr;

    while (L1 != nullptr && L2 != nullptr)
    {
        if (L1->data < L2->data)
        {
            if (mergedHead == nullptr)
            {
                mergedHead = mergedTail = L1;
            }
            else
            {
                mergedTail->next = L1;
                mergedTail = L1;
            }
            L1 = L1->next;
        }
        else if (L1->data > L2->data)
        {
            if (mergedHead == nullptr)
            {
                mergedHead = mergedTail = L2;
            }
            else
            {
                mergedTail->next = L2;
                mergedTail = L2;
            }
            L2 = L2->next;
        }
        else
        {
            if (mergedHead == nullptr)
            {
                mergedHead = mergedTail = L1;
            }
            else
            {
                mergedTail->next = L1;
                mergedTail = L1;
            }
            L1 = L1->next;
            LinkList temp = L2;
            L2 = L2->next;
            delete temp;
        }
    }

    if (L1 != nullptr)
    {
        mergedTail->next = L1;
    }
    else if (L2 != nullptr)
    {
        mergedTail->next = L2;
    }

    return mergedHead;
}

#endif