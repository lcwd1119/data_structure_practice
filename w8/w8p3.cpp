#include <iostream>
#define max_size 100
using namespace std;

class Stack
{
    int num[max_size];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    bool isfull()
    {
        if(top == max_size -1)
            return true;
        return false;
    }
    bool isempty()
    {
        if(top == -1)
            return true;
        return false;
    }
    void push(int n)
    {
        if(isfull())
            return;
        top++;
        num[top] = n;
    }
    bool pop(int &n)
    {
        if(isempty())
            return false;
        n = num[top];
        top--;
        return true;
    }
};

int main()
{
    Stack stack;
    string postfix;
    getline(cin,postfix);
    for(int i = 0,count = 0,a,b;i < postfix.size();i++)
    {
        if(postfix[i]>='0' && postfix[i] <= '9')
        {
            count = count*10 + postfix[i]-'0';
        }
        else
        {
            if(count!=0)
            {
                stack.push(count);
            }
            else if(postfix[i] == ' ')
                continue;
            else
            {
                stack.pop(b);
                stack.pop(a);
                switch (postfix[i]) {
                    case '+':
                        stack.push(a+b);
                        break;
                    case '-':
                        stack.push(a-b);
                        break;
                    case '*':
                        stack.push(a*b);
                        break;
                    case '/':
                        stack.push(a/b);
                        break;
                    case '%':
                        stack.push(a%b);
                        break;
                }
            }
            count = 0;
        }
    }
    int ans;
    stack.pop(ans);
    cout << ans << endl;
    return 0;
}