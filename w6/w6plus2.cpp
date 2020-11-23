#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int matrix[size][size];
    for(int i = 0,num = 1;i < size;i++)
        for(int  j = 0;j < size;j++,num++)
            matrix[i][j] = num;

    string op;
    cin >> op;
    int temp[size][size];
    for(int i = 0;i < op.size();i++)
    {
        for(int i = 0;i < size;i++)
            for(int j = 0;j < size;j++)
                temp[i][j] = matrix[i][j];

        if(op[i] == 'H')
            for(int i = 0;i < size;i++)
                for(int j = 0;j < size;j++)
                    matrix[i][j] = temp[i][size-1-j];

        else if(op[i] == 'V')
            for(int i = 0;i < size;i++)
                for(int j = 0;j < size;j++)
                    matrix[i][j] = temp[size-1-i][j];

        else if(op[i] == 'D')
            for(int i = 0;i < size;i++)
                for(int j = 0;j < size;j++)
                    matrix[i][j] = temp[j][i];

    }
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            cout << matrix[i][j];
            if(j != size-1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}