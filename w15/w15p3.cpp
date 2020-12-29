#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs(vector<int> list[],int size,int &counter)
{
    stack<int> sta;
    int isvisit[size] = {};
    int i = 0;
    while (true)
    {
        if(!isvisit[i])
        {
            counter++;
            isvisit[i] = 1;
        }
        int j;
        for(j = 0;j < list[i].size();j++)
        {
            if(!isvisit[list[i][j]])
                break;
        }

        if(j != list[i].size())
        {
            j = list[i][j];
            sta.push(i);
            i = j;
        }
        else
        {
            i = sta.top();
            sta.pop();
            if(sta.empty())
                break;
        }
    }
}
int main()
{
    int size,temp;
    cin >> size;
    vector<int> list[size];
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            cin >> temp;
            if(temp)
                list[i].push_back(j);
        }
    }
    dfs(list,size,temp);
    if(temp == size)
        cout << "1" << endl;
    else
        cout << "-1" << endl;

    return 0;
}