#include <iostream>
#define max_size 100
using namespace std;

class Stack
{
    int c[max_size];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    bool isfull()
    {
        if(top == max_size-1)
            return true;
        return false;
    }

    bool isempty()
    {
        if(top == -1)
            return true;
        return false;
    }

    void push(int num)
    {
        if(isfull())
            return;
        top++;
        c[top] = num;
    }

    bool pop(int &num)
    {
        if(isempty())
            return false;
        num = c[top];
        top--;
        return true;
    }
};

int main()
{
    int train_len;
    cin >> train_len;
    Stack ctrack;
    while (true)
    {
        int temp;
        bool isposible = true;
        for(int i = 1,num=1,maxnum = 0;i <= train_len;i++)
        {
            cin >> temp;
            if (temp == -1)
                break;
            if(temp < maxnum)
            {
                int temp2;
                ctrack.pop(temp2);
                if(temp != temp2)
                {
                    isposible = false;
                }
            }
            else
            {
                if(temp == num)
                {
                    num++;
                    continue;
                }
                if(maxnum < temp)
                {
                    for (int j = num; j < temp; j++)
                        ctrack.push(j);
                    maxnum = temp;
                    num = temp+1;
                }
            }
        }
        if (temp == -1)
            break;
        while (ctrack.pop(temp));
        if(isposible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
