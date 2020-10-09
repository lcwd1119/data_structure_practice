#include <iostream>
using namespace std;

int main()
{
    int total;
    cin >> total;
    int *num = new int[total];
    for(int i = 0;i < total;i++)
    {
        cin >> num[i];
    }
    int min,temp;
    for(int i =0;i < total;i++)
    {
        min = i;
        for(int j = i+1; j < total;j++)
        {
            if(num[j] < num[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = num[min];
            num[min] = num[i];
            num[i] = temp;
        }
    }
    for(int i = 0;i < total;i++)
    {
        cout << num[i];
        if(i != total-1)
        {
            cout << " ";
        }
    }
    cout << endl;
    delete [] num;
    return 0;
}
