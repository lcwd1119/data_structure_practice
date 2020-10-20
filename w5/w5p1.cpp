#include <iostream>
using namespace std;

int main()
{
   int times,sum = 0;
   cin >> times;
   int *nums = new int[times];
    for (int i = 0; i < times; i++) {
        cin >> nums[i];
    }
   for(int j = 0;j < times;j++)
   {
       for (int i = 0; i < times; i++)
       {
           if(j - i <= 1 && j-i >= -1)
           {
               continue;
           }
           if (sum < nums[i] + nums[j]) {
               sum = nums[i] + nums[j];
           }
       }
   }

   cout << sum << endl;
   return 0;
}
