#include <iostream>
#include <cstring>
using namespace std;

void add(int heap[],int inupt,int &index)
{
    index++;
    heap[index] = inupt;
    for(int i = index,temp,posindex;i > 1;i--)
    {
        if(i %2 == 0)
            posindex = i;
        else
            posindex = i-1;

        if(heap[i] < heap[posindex/2])
        {
            temp = heap[i];
            heap[i] = heap[posindex/2];
            heap[posindex/2] = temp;
        }

    }
}

void print(int heap[],int index)
{
    for(int i = 1;i <= index;i++)
        i==index?printf("[%d]%d",i,heap[i]):printf("[%d]%d ",i,heap[i]);
    cout << endl;
}

int main()
{
    char input[100];
    fgets(input,100,stdin);
    strtok(input,"\r\n");
    char *p = strtok(input," ");
    int heep[101] = {0},index = 0;
    while (p)
    {
        add(heep,stoi(p),index);
        print(heep,index);
        p = strtok(nullptr," ");
    }
    return 0;
}