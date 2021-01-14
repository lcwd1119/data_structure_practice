#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
void findindex(vector<int> inorder,int value,int &index)
{
    int tmep = 0;
    for(auto &i : inorder)
    {
        if (i == value) {
            index = tmep;
            return;
        }
        tmep++;
    }
}
int main()
{
    char input[500];
    vector<int> inorder,preorder;
    fgets(input, 500, stdin);
    strtok(input, "\r\n");
    char *p = strtok(input, " ");
    while (p)
    {
        preorder.push_back(stoi(p));
        p = strtok(nullptr," ");
    }
    fgets(input, 500, stdin);
    strtok(input, "\r\n");
    p = strtok(input, " ");
    while (p)
    {
        inorder.push_back(stoi(p));
        p = strtok(nullptr," ");
    }

    vector<int> level[10];
    int index = 0,inind = 0,rootind;
    int lf = 0;
    while (true)
    {

        if (level[index].empty())
        {
            level[index].push_back(preorder.front());
            findindex(inorder,preorder.front(),rootind);
            preorder.erase(preorder.begin());
            index++;
            continue;
        }
        if(preorder.empty())
            break;
        findindex(inorder,preorder.front(),inind);
        if(inind < rootind)
        {

        }
        else if(inind > rootind)
        {

        }
    }

    cout << *find(preorder.begin(),preorder.end(),10) <<  endl;

    for(int j = 0;!level[j].empty();j++) {
        cout << j+1 << ":";
        for (auto &i : level[j]) {
            cout << i;
            if(i != *level[j].end())
                cout << ",";
        }
        cout << endl;
    }
    return 0;
}