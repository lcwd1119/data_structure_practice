#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int times;
    cin >> times;
    getchar();
    for(int i = 0;i < times;i++)
    {
        string temp;
        temp = "";
        cin >> temp;
        getchar();
        for(int j = 0,size = temp.size(); j < size-1; j++)
        {
            if(temp[j] == 'a')
                reverse(temp.begin()+j+1,temp.end());
            else if(temp[j] == 'b')
                temp.append(temp, j + 1, temp.size());
            else if(temp[j] == 'c')
                temp.erase(j+1,2);
            size = temp.size();
        }
        cout << temp << endl;
    }
    return 0;
}