#include <iostream>
#define maxsize 100
using namespace std;

enum Type{
    preOrder,inOrder,postOder
};

class Stack
{
    string data[maxsize];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    bool isfull()
    {
        if(top == maxsize-1)
            return true;
        return false;
    }
    bool isempty()
    {
        if(top == -1)
            return true;
        return false;
    }
    void push(string c)
    {
        if(!isfull())
        {
            top++;
            data[top] = c;
            return;
        }
    }
    string pop()
    {
        if(!isempty())
            return data[top--];
        return 0;
    }
};

int main()
{
    for(int t = 0;t < 3;t++) {
        string func;
        Type type;
        Stack stack;
        getline(cin, func, '\r');
        getchar();
        if(func[0] < '0' || func[0] > '9')
            type = preOrder;
        else if(func[func.size()-1] < '0' || func[func.size()-1] > '9')
            type = postOder;
        else {
            type = inOrder;
            cout << "same\n";
            continue;
        }

        if(type == preOrder)
        {
            for(int i = func.size()-1;i >= 0;i--)
            {
                if(func[i] >= '0' && func[i] <= '9')
                    stack.push(to_string(func[i]-'0'));
                else {
                    string a = stack.pop(),
                            b = stack.pop();
                    stack.push(a + func[i] + b);
                    if(i!=0)
                        stack.push("(" + stack.pop() + ")");
                }
            }
            cout << stack.pop() << endl;
        }
        else if(type == postOder)
        {
            for(int i = 0;i < func.size();i++)
            {
                if(func[i] >= '0' && func[i] <= '9')
                    stack.push(to_string(func[i] - '0'));
                else
                {

                    stack.push(stack.pop() + func[i] + stack.pop());
                    if(i != func.size()-1)
                    {
                        stack.push("(" + stack.pop() + ")");
                    }
                }
            }
            cout << stack.pop() << endl;
        }
    }
    return 0;
}