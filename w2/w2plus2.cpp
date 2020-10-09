#include <iostream>
#include <string>
using namespace std;

int main()
{
    int total;
    cin >> total;
    int *space = new int[total];
    for(int i = 0;i < total;i++)
    {
        space[i] = 1;
    }
    space[0]=0;
    int arr[5],count = 0,shift,tblack = 0;
    string nums;
    getline(cin,nums);
    for(int i = 0;i < nums.length();i++)
    {
        if(nums[i] != ' ')
        {
            arr[count] = nums[i]-48;
            tblack += arr[count];
            count++;
        }
    }
    shift = total - tblack - (count-1);
    int white = 0;
    for(int j = 1;j <= shift+1;j++)
    {
        for (int i = 0; i < count; i++)
        {
            white += arr[i];
            if (white >= total) {
                break;
            }
            space[white] = 0;
            white++;
        }
        white = j;
    }
    for(int i = 0;i < total;i++)
    {
        cout << space[i];
        if(i != total-1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
