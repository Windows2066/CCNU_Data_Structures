#include <bits/stdc++.h>

#include "CircularQueue_SqList.cpp"
// #include "CircularQueue_stl.cpp"
#include "Stack_Sqlist.cpp"
// #include "Stack_stl.cpp"

using namespace std;

constexpr int PARKING_SIZE = 5; // 停车场大小
constexpr int ACCESS_SIZE = 5;  // 便道大小

char Menu()
{
    char choice;
    for (int i = 0; i <= 30; i++)
        cout << "#\n"[i == 30];
    cout << "#       停车场管理系统       #\n";
    cout << "#      进入停车场(输入A)     #\n";
    cout << "#      离开停车场(输入D)     #\n";
    // cout << "#    显示停车场状态(输入S)   #\n";
    // cout << "#     显示便道状态(输入Q)    #\n";
    cout << "#       退出系统(输入0)      #\n";
    for (int i = 0; i <= 30; i++)
        cout << "#\n"[i == 30];
    cout << "请输入指令：";
    cin >> choice;
    return choice;
}

int main()
{
    Stack Parking; // 停车场
    Queue Access;  // 便道
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
                cout << "车位已满，无法进入！" << endl;
            }
            else
            {
                cout << "请输入车号：";
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
                cout << "停车场为空！" << endl;
            }
            else
            {
                cout << "请输入车号：";
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
                    cout << "停车场内没有该车辆！" << endl;
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