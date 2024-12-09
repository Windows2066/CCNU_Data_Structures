#include <bits/stdc++.h>
#include "list_ptr.cpp"
using namespace std;

Node *detectCycle(Node *head)
{
    if (!head)
        return nullptr;
    Node *slow = head;
    Node *fast = head;
    // 判断是否存在环
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    // 如果不存在环
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;
    // 找到环的入口
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    // 创建一个示例链表: 1->2->3->4->5->3 (环入口为节点3)
    Node *head = new Node(1);
    head->next = new Node(2);
    Node *node3 = new Node(3);
    head->next->next = node3;
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = node3; // 创建环
    LinkList entrance = detectCycle(head);
    if (entrance)
        cout << "环的入口节点值为: " << entrance->data << endl;
    else
        cout << "链表中没有环。" << endl;
    return 0;
}