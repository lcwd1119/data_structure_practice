#include <iostream>
using namespace std;

struct listnode{
    int data;
    listnode *nextptr;
};

class linklist
{
    listnode *first;
    listnode *last;
public:
    linklist()
    {
        first = nullptr;
        last = nullptr;
    }
    bool isempty()
    {
        if(first)
            return false;
        return true;
    }
    void addf(int num)
    {
        listnode *temp = new listnode;
        temp->data = num;
        if(isempty())
        {
            first = last = temp;
            temp->nextptr = nullptr;
            return;
        }
        temp->nextptr = first;
        first = temp;
    }
    void adda(int num)
    {
        listnode *temp = new listnode;
        temp->data = num;
        temp->nextptr = nullptr;
        if(isempty())
        {
            first = last = temp;
            return;
        }
        last->nextptr = temp;
        last = temp;
    }
    void addi(int index,int num)
    {
        listnode *temp = new listnode;
        listnode *ind = first;
        temp->data = num;
        for(int i = 0;i < index-1;ind = ind->nextptr)
            i++;
        temp->nextptr = ind->nextptr;
        ind->nextptr = temp;
    }
    void printlist()
    {
        listnode *temp = first;
        cout << "Created Linked list is:  ";
        for(;temp;temp=temp->nextptr)
        {
            cout << temp->data;
            if(temp->nextptr)
                cout << "  ";
            else
                cout << " " << endl;
        }
    }
};

int main()
{
    int times;
    cin >> times;
    for(int i = 0;i < times;i++)
    {
        linklist Linklist;
        while (1)
        {
            char op;
            cin >> op;
            int num;
            if(op == 'f')
            {
                cin >> num;
                Linklist.addf(num);
                Linklist.printlist();
            }
            else if(op == 'a')
            {
                cin >> num;
                Linklist.adda(num);
                Linklist.printlist();
            }
            else if(op == 'i')
            {
                int index;
                cin >> num >> index;
                Linklist.addi(index,num);
                Linklist.printlist();
            }
            else
                break;
        }
        if(i < times-1)
            cout << endl;
    }
    return 0;
}