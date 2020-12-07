#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    int treearr[100] = {0};
    char str[100];
    fgets(str,100,stdin);
    strtok(str,"\r\n");
    char *p = strtok(str," ");
    treearr[0] = 1;
    treearr[1] = stoi(p);
    p = strtok(NULL," ");
    while (p != nullptr) {
        int num = stoi(p);
        int index = 1;
        while (treearr[index] != 0)
        {
            if (num > treearr[index])
                index = index * 2 + 1;
            else
                index = index * 2;
        }
        treearr[index] = num;
        if(index > treearr[0])
            treearr[0] = index;
        p = strtok(NULL," ");
    }
    int nodenum = treearr[0];
    cout << int(log2(nodenum))+1 << endl;
    return 0;
}