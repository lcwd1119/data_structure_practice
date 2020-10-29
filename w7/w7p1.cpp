#include <iostream>
#include <string>
using namespace std;

int main()
{
    int top = -1;
    string temp;
    int result;
    while (1)
    {
        result = 0;
        top = -1;
        cin >> temp;
        if(temp == "end")
            break;
        for(int i = 0;i < temp.length();i++)
        {
            if(temp[i] == '(')
                top++;
            else if(temp[i] == ')')
                top--;
            if(top < -1)
            {
                result=-1;
                break;
            }
        }
        if(top != -1)
            result =-1;
        if(result==-1)
            cout << result << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}