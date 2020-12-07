#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[500];
    fgets(str,500,stdin);
    strtok(str,"\r\n");
    int length = strlen(str);
    int index = 0,maxlen = 0,templength = 0;
    for(int i = 1;i < length;i++)
    {
        for(int j = 1;;j++)
        {
            if(i+j > length || i-j < 0)
                break;
            if(str[i-j] != str[i+j])
                break;
            templength = j;
        }
        if(templength > maxlen)
        {
            maxlen = templength;
            index = i;
        }
    }
    for(int i = index-maxlen;i <= index+maxlen;i++)
        cout << str[i];
    cout << endl;
}