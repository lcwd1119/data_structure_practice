#include <iostream>
using namespace std;
int main()
{
    int total,temp;
    cin >> total;
    int *num = new int[total];
    for(int i = 0;i < total;i++)
    {
        cin >> num[i];
    }
    for(int  i = 1;i < total;i++)
    {
        for(int j = i ; j >0;j--)
        {
            if (num[j] < num[j - 1])
            {
                temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
        }
        if(i == 1 || i == 2)
        {
            for(int j = 0;j <= i;j++)
            {
                cout << num[j];
                if(j != i)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
    for(int i = 0;i < total;i++)
    {
        cout << num[i];
        if(i!=total-1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
