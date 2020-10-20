#include <iostream>
using namespace std;
void hanoi(int n)
{
    if(n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        hanoi(n - 1);
        cout << n << endl;
        hanoi(n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n);
    return 0;
}