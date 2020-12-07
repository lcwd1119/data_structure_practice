#include <iostream>
using namespace std;

struct thing
{
    char name;
    float value;
    float weight;
};

class Stack
{
    int top;
    int maxweight;
    thing store[10];
public:
    Stack(int maxw)
    {
        top = -1;
        maxweight = maxw;
    }
    float getweight()
    {
        float weight = 0;
        for(int i = 0;i <= top;i++)
            weight += store[i].weight;
        return weight;
    }
    bool isempty()
    {
        if(top == -1)
            return true;
        return false;
    }
    bool push(thing item)
    {
        if(getweight() + item.weight > maxweight)
            return false;
        top++;
        store[top] = item;
        return true;
    }
    bool pop(thing &popitem)
    {
        if(!isempty())
        {
            top--;
            popitem = store[top+1];
            return true;
        }
        return false;
    }
    void print()
    {
        float sumv = 0;
        for(int i = top;i > -1;i--)
        {
            printf("%c %.1f %.1f\n",store[i].name,store[i].value,store[i].weight);
            sumv += store[i].value;
        }
        printf("weight:%.1f\n",getweight());
        printf("value:%.1f\n",sumv);
    }
};

int main()
{
    Stack backpack(20);
    for(int i = 0;i < 5;i++)
    {
        char name;
        float value, weight;
        cin >> name >> value >> weight;
       // getchar();
        if(!backpack.push({name,value,weight}))
        {
            Stack floor(10000);
            thing temp;
            while (backpack.pop(temp))
            {
                if(value > temp.value && backpack.getweight() + weight <= 20)
                {
                    temp = {name, value, weight};
                    break;
                }
                floor.push(temp);
            }
            thing flooritem;
            while (floor.pop(flooritem))
                backpack.push(flooritem);
            backpack.push(temp);
        }
    }
    backpack.print();
    return 0;
}