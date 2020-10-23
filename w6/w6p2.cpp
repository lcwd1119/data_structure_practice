#include <iostream>
#define max_size 100
using namespace std;

typedef struct {
    int row;
    int col;
    int val;
}matrix;

int main()
{
    matrix a[max_size],b[max_size];
    int count[max_size] = {0};
    cin >> a[0].row >> a[0].col >> a[0].val;
    b[0].row = a[0].col;b[0].col = a[0].row;
    b[0].val = a[0].val;
    for(int i = 1;i <= a[0].val;i++)
    {
        cin >> a[i].row >> a[i].col >> a[i].val;
        count[a[i].col]++;
    }
    int startp[max_size] = {0};
    startp[0] = 1;
    for(int i = 1;i <= a[0].col;i++)
    {
        startp[i] = startp[i-1] + count[i - 1];
    }
    for(int i = 1;i <= a[0].val;i++)
    {
        b[startp[a[i].col]].val = a[i].val;
        b[startp[a[i].col]].row = a[i].col;
        b[startp[a[i].col]].col = a[i].row;
        startp[a[i].col]++;
    }
    for(int i = 0;i <= a[0].val;i++)
        cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
    return 0;
}