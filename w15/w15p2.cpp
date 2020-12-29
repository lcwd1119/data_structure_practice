#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfs(vector<int> list[],int size)
{
    stack<int> sta;
    int isvisit[size] = {};
    int i = 0;
    while (true)
    {
        if(!isvisit[i])
        {
            if(isvisit[0])
                cout << " ";
            cout << i;
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

void bfs(vector<int> list[],int size)
{
    queue<int> que;
    int isvisit[size] = {};
    int i =0;
    while (true)
    {
        if(!isvisit[i])
        {
            if(isvisit[0])
                cout << " ";
            cout << i;
            isvisit[i] = 1;
        }
        for(auto &j : list[i])
        {
            if(!isvisit[j])
            {
                if(isvisit[0])
                    cout << " ";
                cout << j;
                isvisit[j] = 1;
                que.push(j);
            }
        }
        if(que.empty())
            break;
        i = que.front();
        que.pop();
    }
}
int main()
{
    int num1,num2,max_size = 0;
    vector<int> list[100];
    while (cin >> num1 >> num2)
    {
        if(max(num1,num2) > max_size)
            max_size = max(num1,num2);
        list[num1].push_back(num2);
        list[num2].push_back(num1);
    }
    max_size++;
    cout << "Depth First Search:" << endl;
    dfs(list,max_size);
    cout << endl << endl << "Breadth First Search:" << endl;
    bfs(list,max_size);
    cout << endl;
    return 0;
}