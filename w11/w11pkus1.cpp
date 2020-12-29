#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node{
    string data;
    int times;
    node *nextptr;
};

class Link_list
{
    node *first;
public:
    Link_list()
    {
        first = nullptr;
    }
    bool find(string input)
    {

        for(node *index = first;index;index = index->nextptr)
        {
            string temp1 = index->data;
            string temp2 = input;
            transform(temp1.begin(),temp1.end(),temp1.begin(),::tolower);
            transform(temp2.begin(),temp2.end(),temp2.begin(),::tolower);
            if(temp1 == temp2)
            {
                index->times++;
                return true;
            }
        }
        return false;
    }
    void add(string input)
    {
        if(!first)
        {
            node *temp = new node;
            temp->data = input;
            temp->times = 1;
            temp->nextptr = nullptr;
            first = temp;
            return;
        }

        if(find(input))
            return;

        node *index,**preindexptr = &first;
        for(index = first;index;index = index->nextptr)
            preindexptr = &index->nextptr;
        index = new node;
        index->data = input;
        index->times = 1;
        index->nextptr = nullptr;
        *preindexptr = index;
    }

    void insert(int ind,string input)
    {
        if (find(input))
            return;
        int count = 1;
        for(node *index = first;index;index = index->nextptr)
        {
            if(count == ind)
            {
                node *temp = new node;
                temp->data = input;
                temp->times = 1;
                temp->nextptr = index->nextptr;
                index->nextptr = temp;
                return;
            }
            count++;
        }
    }

    void print()
    {
        for(node *index = first;index;index = index->nextptr)
            cout << index->data << ", " << index->times << endl;
    }
};

int main()
{
    string input;
    Link_list list;
    while (true)
    {
        cin >> input;
        if(input == "#Finish")
            break;
        list.add(input);
    }

    while (true)
    {
        cin >> input;
        if(input == "#Exit")
            break;
        else if(input == "#Print")
            list.print();
        else if(input == "#Insert")
        {
            int ind;
            cin >> ind >> input;
            list.insert(ind,input);
        }
        else if(input == "#Add")
        {
            cin >> input;
            list.add(input);
        }
    }
    return 0;
}