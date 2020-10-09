#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int matrix[size][size], yaxis = 0, xaxis = (size-1)/2;
    for(int i = 0;i < size;i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j]=0;
        }
    }
    matrix[yaxis][xaxis] = 1;
    int x=xaxis,y=yaxis;
    for(int i = 2;;)
    {
        y--;
        x++;
        if(y < 0) y += size;
        if(x > size-1) x -= size;
        if(matrix[y][x]!=0)
        {
            yaxis++;
            if(y < 0) y -= 3;
            matrix[yaxis][xaxis]=i;
            y=yaxis;
            x=xaxis;
            i++;
            continue;
        }
        matrix[y][x] = i;
        yaxis=y;
        xaxis=x;
        i++;
        if(i==(size*size)+1)break;
    }
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            cout << matrix[i][j];
            if(j < size -1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

