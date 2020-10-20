#include <iostream>
using namespace std;

int stair(int n)
{
    if(n >0)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
    }
    return stair(n-1)+stair(n-2);
}

int main()
{
    int stairs;
    cin >> stairs;
    cout << stair(stairs) << endl;
}