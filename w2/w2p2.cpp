#include <iostream>
using namespace std;
int binarysearch(int num[],int target,int right,int left)
{
    int middle = (right+left)/2;
    if(left <= right)
    {
        if(num[middle] < target)
        {
            return binarysearch(num,target,right,middle+1);
        }
        else if(num[middle] == target)
        {
            return middle;
        }
        else if(num[middle] > target)
        {
            return binarysearch(num,target,middle-1,left);
        }
    }
    return -1;
}
int main()
{
    int target,total;
    cin >> target >> total;
    int *num = new int[total];
    for(int i = 0;i < total;i++)
    {
        cin >> num[i];
    }
    cout << binarysearch(num,target,total-1,0) << endl;
    return 0;
}
