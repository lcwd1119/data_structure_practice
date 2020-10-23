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

void fadd(polynomial *p,polynomial *aindex,polynomial *aend,polynomial *bindex,polynomial *bend,int &total)
{
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
    //a
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
    //b

    polynomial *aindex = astart,*bindex = bstart;
    polynomial *cstart,*cend,*dstart,*dend;
    if(atimes>1)
    {
        cstart = p + total;
        for (int i = 0; aindex <= astart+1;)
        {
            p[total] = {aindex->coef * bindex->coef, aindex->expon + bindex->expon};
            bindex += 1;
            total++;
            if (bindex > bend && i < 1) {
                aindex += 1;
                bindex = bstart;
                cend = p + total - 1;
                dstart = p + total;
                i++;
            }
            else if (bindex > bend && aindex == astart+1)
            {
                dend = p + total - 1;
                fstart = p + total;
                fadd(p, cstart, cend, dstart, dend, total);
                fend = p + total - 1;
                bindex = bstart;
                aindex += 1;
            }
        }
    }

    cstart = p + total;
    while(aindex <= aend)
    {
        p[total] = {aindex->coef * bindex->coef, aindex->expon + bindex->expon};
        bindex += 1;
        total++;
        if(bindex > bend)
        {
            cend = p+total-1;
            dstart = fstart;
            dend = fend;
            fstart = p + total;
            fadd(p, cstart, cend, dstart, dend, total);
            fend = p + total - 1;
            cstart = p+total;
            aindex += 1;
            bindex = bstart;
        }
    }
    print(fstart,fend);
    return 0;
}