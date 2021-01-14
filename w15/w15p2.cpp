#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> lis[100];

void dfs(vector<int> list,int index,int isvisit[])
{
    if(isvisit[index] == 0)
    {
        if(isvisit[0])
            cout << " ";
        cout << index;
        isvisit[index] = 1;
        dfs(lis[index],index,isvisit);
    }
    for(int i = 0;i < list.size();i++)
    {
        if(isvisit[list[i]] == 0)
        {
            if(isvisit[0])
                cout << " ";
            cout << list[i];
            isvisit[list[i]] = 1;
            dfs(lis[list[i]],list[i],isvisit);
        }
    }
}

void bfs(vector<int> list,int index,int isvisit[],queue<int> &que)
{
    if(isvisit[index] == 0)
    {
        if(isvisit[0])
            cout << " ";
        cout << index;
        que.push(index);
        isvisit[index] = 1;
    }
    for(int i = 0;i < list.size();i++)
    {
        if(isvisit[list[i]] == 0)
        {
            if(isvisit[0])
                cout << " ";
            cout << list[i];
            que.push(list[i]);
            isvisit[list[i]] = 1;
        }
    }
    que.pop();
    if(que.empty())
        return;
    bfs(lis[que.front()], que.front(), isvisit,que);
}
int main()
{
    int num1,num2,max_size = 0;
    while (cin >> num1 >> num2)
    {
        if(num1 == -1)
            break;
        if(max(num1,num2) > max_size)
            max_size = max(num1,num2);
        lis[num1].push_back(num2);
        lis[num2].push_back(num1);
    }
    max_size++;
    cout << "Depth First Search:" << endl;
    int isvisit[max_size] = {};
    dfs(lis[0],0,isvisit);
    cout << endl << endl << "Breadth First Search:" << endl;
    int isvisit2[max_size] = {},count = 0;
    queue<int> que;
    bfs(lis[0],0,isvisit2,que);
    cout << endl;
    return 0;
}