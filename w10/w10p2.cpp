#include <iostream>
using namespace std;

struct listnode{
    int data;
    listnode *nextptr;
};

class Linklist{
    listnode *first;
    int n,a,b;
public:
    Linklist(int x,int y,int z)
    {
        first = nullptr;
        n = x;
        a = y;
        b = z;
    }
    void addlist()
    {
        for(int i = 1;i <= n;i++)
        {
            listnode *temp = new listnode;
            listnode *index;
            temp->data = i;
            if(!first)
            {
                index = first = temp;
                temp->nextptr = nullptr;
                continue;
            }
            index->nextptr = temp;
            temp->nextptr = nullptr;
            index = temp;
        }
    }

    listnode *findpre(listnode *index)
    {
        listnode *preindex = first;
        for(;preindex->nextptr != index;preindex = preindex->nextptr);
        return preindex;
    }

    void leavep()
    {
        listnode *index = first;
        for(int i = 1;i < a;i++,index = index->nextptr);
        for(int i = 1,count = 0;index;i++)
        {
            if (i%b == 0)
            {
                if(index == first)
                {
                    cout << index->data;
                    first = index->nextptr;
                    delete index;
                    index = first;
                }
                else if(index->nextptr == nullptr)
                {
                    cout << index->data;
                    listnode *preindex = findpre(index);
                    delete index;
                    preindex->nextptr = nullptr;
                    index = first;
                }
                else
                {
                    cout << index->data;
                    listnode *preindex = findpre(index);
                    preindex->nextptr = index->nextptr;
                    delete index;
                    index = preindex->nextptr;
                }
                count++;
                if(count != n)
                    cout << " ";
                else
                    cout << endl;
            }
            else if(index->nextptr == nullptr)
                index =first;
            else
                index = index->nextptr;
        }
    }
};

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    Linklist linklist(n,a,b);
    linklist.addlist();
    linklist.leavep();
    return 0;
}