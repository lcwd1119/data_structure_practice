#include <iostream>
#include <cstring>
#define max_size 30
using namespace std;

int main()
{
    int top = -1;
    char temp[max_size];
    int result;
    while (1)
    {
        fgets(temp,max_size,stdin);
        strtok(temp,"\r\n");
        if(strcmp(temp,"end")==0)
            break;
        for(int i = 0;i < strlen(temp);i++)
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
        if(result==-1)
            cout << result << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}