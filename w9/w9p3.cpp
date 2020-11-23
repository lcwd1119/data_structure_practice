#include <iostream>
#include <string>
using namespace std;

struct Stacknode
{
    string data;
    Stacknode *nextptr;
};

class Linkstack
{
    Stacknode *top;
public:
    Linkstack()
    {
        top = nullptr;
    }
    void push(string c)
    {
        Stacknode *temp = new Stacknode;
        temp->data = c;
        if(top == nullptr)
        {
            top = temp;
            temp->nextptr = nullptr;
            return;
        }
        temp->nextptr = top;
        top = temp;
    }
    bool pop()
    {
        if(top != nullptr)
        {
            Stacknode *temp = top;
            top = top->nextptr;
            delete temp;
            return true;
        }
        return false;
    }
    Stacknode *findpre(Stacknode *index)
    {
        Stacknode *preindex = top;
        for(;preindex->nextptr != index;preindex = preindex->nextptr);
        return preindex;
    }
    void findpair(string target)
    {

        Stacknode *index = top;
        bool isfind;
        for(;index;index = index->nextptr)
        {
            isfind = false;
            if(index->data == target)
            {
                isfind = true;
                break;
            }
        }
        if(isfind)
        {
            if(top == index)
                pop();
            else if(index->nextptr == nullptr)
            {
                Stacknode *preindex = findpre(index);
                delete index;
                preindex->nextptr = nullptr;
            }
            else
            {
                Stacknode *preindex = findpre(index);
                Stacknode *temp = index;
                preindex->nextptr = index->nextptr;
                delete temp;
            }
        }
        else
            push(target);
    }
};

int main()
{
    int times;
    cin >> times;
    int *round = new int[times]();
    for(int i = 0;i < times;i++)
        cin >> round[i];
    getchar();
    //getchar();
    for(int i = 0;i < times;i++)
    {
        Linkstack list;
        string str;
        for(int j = 0;j < round[i];j++)
        {
            getline(cin,str);
            if(j == 0)
                list.push(str);
            else
                list.findpair(str);
        }
        int count = 0;
        while (list.pop())
            count++;
        cout << count << endl;
    }
    return 0;
}