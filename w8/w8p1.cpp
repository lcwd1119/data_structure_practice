#include <iostream>
#include <string>
#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100   /* max size of expression */
using namespace std;

typedef struct
{
   char op;
   int isp;
   int icp;
}operators;

class Stack
{
    operators data[MAX_STACK_SIZE];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    bool isfull(){
        if (top == MAX_STACK_SIZE - 1)
            return true;
        return false;
    }
    bool isempty(){
        if(top == -1)
            return true;
        return false;
    }
    bool isadd(operators c)
    {
        if(isfull())
            return false;
        if(isempty())
            return true;
        if(c.icp <= data[top].isp)
            return false;
        return true;
    }

    void add(operators c)
    {
        while (!isadd(c))
        {
            char temp;
            pop(temp);
            cout << ' ' << temp;
        }
        push(c);
    }

    bool push(operators c){
        if (isfull())
            return false;
        top++;
        data[top] = c;
        return true;
    }
    bool pop(char &c){
        if(isempty())
            return false;
        c = data[top].op;
        top--;
        return true;
    }

};

int main()
{
    int times;
    Stack stack;
    cin >> times;
    getchar();
    //getchar();
    for(int i = 0;i < times;i++)
    {
        string expr;
        expr = "";
        getline(cin, expr);
        bool isprint = false;
        for(int j = 0;j < expr.length();j++)
        {
            char temp =' ';
            if(expr[j] == ' ')
                continue;
            if(expr[j] >= '0' && expr[j] <= '9') {
                if(isprint)
                    cout << ' ';
                isprint = true;
                cout << expr[j];
                continue;
            }
            switch (expr[j])  {
                case    '(' :
                    stack.add({'(',0,20});
                    break;
                case    ')' :
                    while (temp!='(')
                    {
                        stack.pop(temp);
                        if(temp=='(')
                            continue;
                        cout << ' ' << temp;
                    }
                    break;
                case    '+' :
                    stack.add({'+',12,12});
                    break;
                case    '-' :
                    stack.add({'-',12,12});
                    break;
                case    '/' :
                    stack.add({'/',13,13});
                    break;
                case    '*' :
                    stack.add({'*',13,13});
                    break;
                case    '%' :
                    stack.add({'%',13,13});
                    break;
            }
        }
        char temp = ' ';
        while (stack.pop(temp))
            cout << ' ' << temp;
        cout << endl;
    }
    return 0;
}