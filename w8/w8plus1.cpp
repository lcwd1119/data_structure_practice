#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int min,max;
    cin >> min >> max;
    for(int i = min;i <= max;i++)
    {
        string temp = to_string(i);
        string rtemp = temp;
        reverse(rtemp.begin(),rtemp.end());
        if(temp == rtemp)
            cout << temp << " ";
    }
    cout << endl;
    return 0;
}