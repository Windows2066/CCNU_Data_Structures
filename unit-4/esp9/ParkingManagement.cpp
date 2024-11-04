#include <bits/stdc++.h>

#include "CircularQueue_SqList.cpp"
// #include "CircularQueue_stl.cpp"
#include "Stack_Sqlist.cpp"
// #include "Stack_stl.cpp"

using namespace std;

constexpr int PARKING_SIZE = 5; // ͣ������С
constexpr int ACCESS_SIZE = 5;  // �����С

char Menu()
{
    char choice;
    for (int i = 0; i <= 30; i++)
        cout << "#\n"[i == 30];
    cout << "#       ͣ��������ϵͳ       #\n";
    cout << "#      ����ͣ����(����A)     #\n";
    cout << "#      �뿪ͣ����(����D)     #\n";
    // cout << "#    ��ʾͣ����״̬(����S)   #\n";
    // cout << "#     ��ʾ���״̬(����Q)    #\n";
    cout << "#       �˳�ϵͳ(����0)      #\n";
    for (int i = 0; i <= 30; i++)
        cout << "#\n"[i == 30];
    cout << "������ָ�";
    cin >> choice;
    return choice;
}

int main()
{
    Stack Parking; // ͣ����
    Queue Access;  // ���
    InitStack(Parking);
    InitQueue(Access);
    int choice, cnt = 0;
    choice = Menu();
    while (choice != '0')
    {
        if (choice == 'A')
        {
            if (cnt > PARKING_SIZE + ACCESS_SIZE)
            {
                cout << "��λ�������޷����룡" << endl;
            }
            else
            {
                cout << "�����복�ţ�";
                int car;
                cin >> car;
                if (cnt < PARKING_SIZE)
                {
                    Push(Parking, car);
                    cnt++;
                }
                else
                {
                    EnQueue(Access, car);
                    cnt++;
                }
            }
            StackTraverse(Parking);
            QueueTraverse(Access);
        }
        else if (choice == 'D')
        {
            if (cnt == 0)
            {
                cout << "ͣ����Ϊ�գ�" << endl;
            }
            else
            {
                cout << "�����복�ţ�";
                int car;
                cin >> car;
                Stack TempParking;
                InitStack(TempParking);
                bool isFound = false;
                while (!StackEmpty(Parking))
                {
                    int e;
                    Pop(Parking, e);
                    if (e == car)
                    {
                        isFound = true;
                        break;
                    }
                    Push(TempParking, e);
                }
                if (isFound)
                {
                    while (!StackEmpty(TempParking))
                    {
                        int e;
                        Pop(TempParking, e);
                        if (e != car)
                            Push(Parking, e);
                    }
                    cnt--;
                    DestroyStack(TempParking);
                    if (!QueueEmpty(Access))
                    {
                        int e;
                        DeQueue(Access, e);
                        Push(Parking, e);
                        cnt++;
                    }
                }
                else
                {
                    cout << "ͣ������û�иó�����" << endl;
                    while (!StackEmpty(TempParking))
                    {
                        int e;
                        Pop(TempParking, e);
                        Push(Parking, e);
                    }
                    DestroyStack(TempParking);
                }
            }
            StackTraverse(Parking);
            QueueTraverse(Access);
        }
        choice = Menu();
    }
    DestroyStack(Parking);
    DestroyQueue(Access);
    return 0;
}