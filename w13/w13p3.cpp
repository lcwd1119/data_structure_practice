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

void del(int heap[],int &index)
{
    heap[1] = heap[index];
    index--;
    for(int i = 1,temp;i < index;)
    {
        if((heap[i] > heap[2*i] || heap[i] > heap[2*i+1]) && ( 2*i <= index || 2*i+1 <= index))
        {
            if(heap[i*2] < heap[i*2+1])
            {
                temp = heap[i];
                heap[i] = heap[i*2];
                heap[i*2] = temp;
                i *=2;
            }
            else if(heap[i*2] > heap[i*2+1])
            {
                temp = heap[i];
                heap[i] = heap[i*2+1];
                heap[i*2+1] = temp;
                i *=2+1;
            }
        }
        else
            break;
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
        p = strtok(nullptr," ");
    }
    for(int i = 0,posindex = index;i < index;i++)
    {
        print(heep,posindex);
        del(heep,posindex);
    }
    return 0;
}