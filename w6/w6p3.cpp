#include <iostream>
#include <stdio.h>
#define max_size 100
using namespace std;

typedef struct {
    int row;
    int col;
    int val;
}matrix;

int main()
{
    matrix a[max_size],at[max_size];
    int times,size = 0;
    cin >> times;
    getchar();
    getchar();
    for(int i = 0;i < times;i++)
    {
        scanf("(%d:%d)=%d",&a[i].row,&a[i].col,&a[i].val);
        getchar();
        getchar();
        if(a[i].row > size)
            size = a[i].row;
        if(a[i].col > size)
            size = a[i].col;
    }

   /* for(int i = 0;i < times;i++)
    {
        at[i].val = a[i].val;
        at[i].row = a[i].col;
        at[i].col = a[i].row;
    }*/

    for(int nrow = 1;nrow<=size;nrow++)
    {
        for(int ncol = 1;ncol <= size;ncol++)
        {
            int sum = 0;
            for (int i = 0; i < times; i++)
            {
                if (a[i].row == nrow)
                {
                    for (int j = 0; j < times; j++)
                    {
                        if (a[j].row == ncol && a[i].col == a[j].col)
                            sum += a[i].val * a[j].val;

                    }
                }
            }
            cout << sum;
            if(ncol != size)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}