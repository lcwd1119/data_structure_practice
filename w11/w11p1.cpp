#include <iostream>
#include <cstring>
using namespace std;

struct listnode{
    listnode *nextptr;
    int data;
};

class linklist
{
    listnode *first;
    listnode *last;
public:
    linklist()
    {
        first = last = nullptr;
    }
    void add(int num)
    {
        listnode *temp = new listnode;
        temp->data = num;
        temp->nextptr = nullptr;
        if(!first)
            first = last = temp;
        else
        {
            last->nextptr = temp;
            last = temp;
        }
    }
    void invert()
    {
        listnode *lead = first,
                 *middle = nullptr,
                 *trail = nullptr;
        last = first;
        while (lead)
        {
            trail = middle;
            middle = lead;
            lead = lead->nextptr;
            middle->nextptr = trail;
        }
        first = middle;
        last->nextptr = nullptr;
    }
    void printlist()
    {
        for(listnode *index = first;index;index = index->nextptr)
        {
            cout << index->data;
            if(index->nextptr)
                cout << " ";
        }
        cout << endl;
    }
};

int main()
{
    char num[100];
    fgets(num,100,stdin);
    strtok(num,"\r\n");
    char *p = strtok(num," ");
    int input;
    linklist list;
    while (p)
    {
        input = stoi(p);
        list.add(input);
        p = strtok(nullptr," ");
    }
    list.invert();
    list.printlist();
    return 0;
}