#include <iostream>
#define MAX_TERM 10000
using namespace std;

typedef struct
{
    float coef; //係數
    unsigned int expon; //次數
}polynomial;

void print(polynomial *start,polynomial *end)
{
    for(polynomial *i = start;i <= end;i++)
    {
        if(i->coef == 0)
            continue;
        if(i != start && i->coef > 0)
            printf("+");
        if(i->expon == 0)
            printf("%.2lf",i->coef);
        else
            if(i->expon == 1)
                printf("%.2lfx",i->coef,i->expon);
            else
                printf("%.2lfx^%d",i->coef,i->expon);
    }
    cout << endl;
}

int main()
{
    polynomial p[MAX_TERM];
    int atimes,btimes,total = 0;
    polynomial *astart,*aend,*bstart,*bend,*fstart,*fend;
    cin >> atimes;
    astart = p;
    for(int i = 0;i < atimes;i++)
    {
        cin >> p[total].coef;
        cin >> p[total].expon;
        total++;
    }
    aend = p +total-1;
    print(astart,aend);
    cin >> btimes;
    bstart = p +total;
    for(int i = 0;i < btimes;i++)
    {
        cin >> p[total].coef;
        cin >> p[total].expon;
        total++;
    }
    bend = p +total-1;
    print(bstart,bend);
    polynomial *aindex = astart,*bindex = bstart;
    fstart = p +total;
    while (aindex <= aend && bindex <= bend)
    {
        if(aindex->expon > bindex->expon)
        {
            p[total] = {aindex->coef,aindex->expon};
            aindex +=1;
        }
        else if(bindex->expon > aindex->expon)
        {
            p[total] = {bindex->coef,bindex->expon};
            bindex += 1;
        }
        else
        {
            p[total] = {aindex->coef+bindex->coef,aindex->expon};
            aindex+=1;
            bindex+=1;
        }
        total++;
    }
    while (aindex <= aend)
    {
        p[total] = {aindex->coef,aindex->expon};
        aindex+=1;
        total++;
    }
    while (bindex <= bend)
    {
        p[total] = {bindex->coef,bindex->expon};
        bindex+=1;
        total++;
    }
    fend = p + total-1;
    print(fstart,fend);
    return 0;
}

