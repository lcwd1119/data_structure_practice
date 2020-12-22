#include <iostream>
#define maxweight 20
using namespace std;

struct thing{
    char name;
    float value;
    float weight;
    float cp;
};

class Linklist
{
    struct node{
        thing data;
        node *nextptr;
    };
    node *first;
public:
    Linklist()
    {
        first = nullptr;
    }

    float getweight()
    {
        if(!first)
            return 0;
        int weight = 0;
        node *temp = first;
        while (temp) {
            weight += temp->data.weight;
            temp = temp->nextptr;
        }
        return weight;
    }

    bool isempty()
    {
        if(first)
           return false;
        return true;
    }

    void add(thing input)
    {
        node *temp = new node;
        temp->data = input;
        temp->nextptr = nullptr;
        if(isempty())
            first = temp;
        else if(input.cp < first->data.cp)
        {
            temp->nextptr = first;
            first = temp;
        }
        else if(input.cp == first->data.cp)
        {
            if(input.weight > first->data.weight) {
                temp->nextptr = first;
                first = temp;
            }
            else
            {
                temp->nextptr = first->nextptr;
                first->nextptr = temp;
            }
        }
        else
        {
            for(node *index = first,*preindex = first;index;index = index->nextptr)
            {
                if(temp->data.cp > index->data.cp)
                    preindex = index;
                else if(temp->data.cp == index->data.cp && temp->data.weight > index->data.weight)
                {
                    temp->nextptr = index;
                    preindex->nextptr = temp;
                }
                else{
                    preindex->nextptr = temp;
                    temp->nextptr = index;
                }
            }
        }
    }

    void del()
    {
        node *temp = first;
        first = first->nextptr;
        delete temp;
    }

    bool check(thing input)
    {
        if(input.cp < first->data.cp)
            return false;
        return true;
    }

    void print()
    {
        int sum = 0;
        for(node *index = first;index;index = index->nextptr)
        {
            sum += index->data.value;
            if(index == first) {
                cout << index->data.name;
                continue;
            }
            cout << " " << index->data.name;
        }
        printf("\ntotal weight:%.2f\n",getweight());
        cout << "total value:" << sum << endl;
    }
};

int main()
{
    char name;
    float value,weight;
    Linklist backpack;
    while (true)
    {
        cin >> name;
        if(name == '-')
            break;
        cin >> value >> weight;
        getchar();
        thing temp = {name,value,weight,value/weight};
        if(backpack.getweight() + temp.weight <= 20)
            backpack.add(temp);
        else
        {
            while (backpack.getweight() + temp.weight > 20)
            {
                if(!backpack.check(temp))
                    break;
                backpack.del();
            }
            if(backpack.getweight() + temp.weight <= 20)
                backpack.add(temp);
        }
    }
    backpack.print();
    return 0;
}