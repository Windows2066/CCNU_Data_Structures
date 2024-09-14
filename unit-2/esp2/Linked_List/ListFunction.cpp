#ifdef list_ptr_h
#include "list_ptr.cpp"
void MergeLists(List &L1, List &L2)
{
    if (ListEmpty(L2))
        return;
    if (ListEmpty(L1))
    {
        L1.head = L2.head;
        L1.tail = L2.tail;
        L1.length = L2.length;
        L2.head = nullptr;
        L2.tail = nullptr;
        L2.length = 0;
        return;
    }
    L1.tail->next = L2.head;
    L2.head->prev = L1.tail;
    L1.tail = L2.tail;
    L1.length += L2.length;
    L2.head = nullptr;
    L2.tail = nullptr;
    L2.length = 0;
}

void PurifyList(List &L)
{
    LNode *it = L.head;
    while (it != nullptr)
    {
        LNode *runner = it->next;
        while (runner != nullptr)
        {
            if (runner->data == it->data)
            {
                LNode *temp = runner;
                runner = runner->next;
                if (temp == L.tail)
                {
                    L.tail = temp->prev;
                }
                if (temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                --L.length;
            }
            else
            {
                runner = runner->next;
            }
        }
        it = it->next;
    }
}

#endif

#ifdef list_stl_h
#include "list_stl.cpp"
void MergeLists(List &L1, List &L2)
{
    L1.data.splice(L1.data.end(), L2.data);
}

void PurifyList(List &L)
{
    auto it = L.data.begin();
    while (it != L.data.end())
    {
        auto runner = std::next(it);
        while (runner != L.data.end())
        {
            if (*runner == *it)
            {
                runner = L.data.erase(runner);
            }
            else
            {
                ++runner;
            }
        }
        ++it;
    }
}
#endif