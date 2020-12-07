#include <iostream>
using namespace std;

struct poly
{
    int coef;
    int expo;
};

struct listnode
{
    poly data;
    listnode *nextptr;
};

class Linklist
{
    listnode *first;
    listnode *last;
public:
    Linklist()
    {
        first = last = nullptr;
    }
    void add(poly input)
    {
        listnode *temp = new listnode;
        temp->data = input;
        temp->nextptr = nullptr;
        if(!first)
            first = last = temp;
        else if(temp->data.expo > first->data.expo)
        {
            temp->nextptr = first;
            first = temp;
        }
        else if(temp->data.expo > last->data.expo)
        {
            listnode *index;
            for(index = first;index->nextptr->data.expo > temp->data.expo;index = index->nextptr);
            temp->nextptr = index->nextptr;
            index->nextptr = temp;
        }
        else
        {
            last->nextptr = temp;
            last = temp;
        }
    }
    void printpoly()
    {
        for(listnode *it = first;it;it = it->nextptr)
        {
            if(it->data.coef == 0)
                continue;
            cout << it->data.coef;
            if(it->data.expo > 1)
                cout << "x^" << it->data.expo;
            else if(it->data.expo == 1)
                cout << 'x';
            if(it->nextptr)
                cout << " + ";
        }
        cout << endl;
    }
    Linklist operator+(Linklist b)
    {
        listnode *aindex = first;
        listnode *bindex = b.first;
        Linklist ans;
        while (aindex && bindex)
        {
            if(aindex->data.expo == bindex->data.expo)
            {
                ans.add({aindex->data.coef+bindex->data.coef,aindex->data.expo});
                aindex = aindex->nextptr;
                bindex = bindex->nextptr;
            }
            else if(aindex->data.expo > bindex->data.expo)
            {
                ans.add(aindex->data);
                aindex = aindex->nextptr;
            }
            else
            {
                ans.add(bindex->data);
                bindex = bindex->nextptr;
            }
        }
        while (aindex)
        {
            ans.add(aindex->data);
            aindex = aindex->nextptr;
        }
        while (bindex)
        {
            ans.add(bindex->data);
            bindex = bindex->nextptr;
        }
        return ans;
    }
    Linklist operator*(Linklist b)
    {
        Linklist temp[100];
        int countn = 0;
        for(listnode *aindex = first;aindex;aindex = aindex->nextptr) {
            for (listnode *bindex = b.first; bindex; bindex = bindex->nextptr)
                temp[countn].add({aindex->data.coef * bindex->data.coef, aindex->data.expo + bindex->data.expo});
        countn++;
        }
        Linklist ans;
        for(int i = 0;i < countn;i++)
            ans = ans + temp[i];
        return ans;
    }
};

ostream &operator<<(ostream &out,Linklist a)
{
    a.printpoly();
    return out;
}

int main()
{
    int coef,expo;
    Linklist A,B;
    while (true) {
        cin >> coef;
        if (coef == -1)
            break;
        cin >> expo;
        A.add({coef,expo});
    }
    while (true)
    {
        cin >> coef;
        if(coef == -1)
            break;
        cin >> expo;
        B.add({coef,expo});
    }
    cout << "add = " << A+B;
    cout << "mult = " << A*B;
    return 0;
}