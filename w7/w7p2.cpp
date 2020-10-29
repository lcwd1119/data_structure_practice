#include <iostream>
using namespace std;

int main()
{
    int size;
     cin >> size;
    int *queue = new int[size];
    int rear = 0,front =0;
    while (1)
    {
        int operation;
        cin >> operation;
        if(operation==1)
        {
            if((rear+1)%size == front)
            {
                cout << "FULL" << endl;
            }
            else
            {
                rear = (rear+1)%size;
                int num;
                cin >> num;
                queue[rear] = num;
            }
        }
        else if(operation == 0)
        {
            if(rear == front)
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                front = (front+1)%size;
                cout << queue[front] <<endl;
            }
        }
        else if(operation == -1)
            break;
    }
}