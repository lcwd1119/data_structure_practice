#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }

    if (n % 2 == 0) {
        return n == 2;
    }

    for (int i = 3; ; i += 2)
    {
        if (i > n / i) {
            break;
        }
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    int num,count;
    cin >> num;
    int digit = 2;
    while(1)
    {
        if(isPrime(num))
        {
            cout << num << endl;
            break;
        }
        if(num == 1)
        {
            break;
        }
        if(isPrime(digit)) {
                count = 0;
                for (int i = 0;; i++) {

                    if (num % digit != 0) {
                        break;
                    }
                    num = num/digit;
                    count++;
                }
                if(count >= 1)
                {
                    cout << digit ;
                    if(count > 1)
                    {
                       cout << "^" << count;
                    }
                    if(num == 1)
                    {
                        break;
                    }
                    cout << " * ";
                }
        }
            digit++;
    }
    return 0;
}
