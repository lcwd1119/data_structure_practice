#include <iostream>
using namespace std;

typedef struct
{
    string title;
    int price;
}product;

struct listnode
{
    product data;
    listnode *nextptr;
};

class Linklist
{
    listnode *first;
public:
    Linklist()
    {
        first = nullptr;
    }
    listnode *find(product target)
    {
        for(listnode *index = first;index;index = index->nextptr)
        {
            if(index->data.title == target.title)
                return index;
        }
        return nullptr;
    }
    void add(product input)
    {
        listnode *temp = new listnode;
        temp->data = input;
        temp->nextptr = nullptr;
        listnode *isfind = find(input);
        if(!first)
            first = temp;
        else if(isfind)
        {
            if(isfind->data.price < temp->data.price)
            {
                listnode *index;
                for(index = isfind;index;index =index->nextptr)
                {
                    if(!index->nextptr)
                        break;
                    if(index->nextptr->data.title != isfind->data.title)
                        break;
                    if(index->nextptr->data.price > temp->data.price)
                        break;
                }
                temp->nextptr = index->nextptr;
                index->nextptr = temp;
            }
            else
            {
                if(isfind == first)
                {
                    temp->nextptr = first;
                    first = temp;
                }
                else{
                    listnode *index;
                    for (index = first; index->nextptr != isfind; index = index->nextptr);
                    temp->nextptr = isfind;
                    index->nextptr = temp;
                }
            }
        }
        else
        {
            listnode *index;
            for(index = first;index->nextptr;index = index->nextptr);
            index->nextptr = temp;
        }
    }
    void print()
    {
        for(listnode *index = first;index;index = index->nextptr)
        {
            cout << index->data.title << ',' << index->data.price << ',';
            if(!index->nextptr)
            {
                cout << endl;
                break;
            }
            while (index->nextptr && index->data.title == index->nextptr->data.title)
            {
                index = index->nextptr;
                cout << index->data.price << ',';
            }
            cout << endl;
        }
    }
};

int main()
{
    Linklist linklist;
    string str;
    int price,times;
    cin >> times;
    for(int i = 0;i < times;i++)
    {
        cin >> str >> price;
        linklist.add({str,price});
    }
    linklist.print();
    return 0;
}