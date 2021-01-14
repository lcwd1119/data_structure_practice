#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void preorder(int tree[],int target,int index,vector<int> &list)
{
    if(tree[index] == 0)
        return;
    list.push_back(tree[index]);
    preorder(tree,target,index*2,list);
    preorder(tree,target,index*2+1,list);
}

void inorder(int tree[],int target,int index,vector<int> &list)
{
    if(tree[index] == 0)
        return;
    inorder(tree,target,index*2,list);
    list.push_back(tree[index]);
    inorder(tree,target,index*2+1,list);
}

void postorder(int tree[],int target,int index,vector<int> &list)
{
    if(tree[index] == 0)
        return;
    postorder(tree,target,index*2,list);
    postorder(tree,target,index*2+1,list);
    list.push_back(tree[index]);
}

int main()
{
    char input[500];
    fgets(input,500,stdin);
    strtok(input,"\r\n");
    char *p = strtok(input," ");
    int tree[500] = {};
    tree[0] = 1;
    tree[1] = stoi(p);
    p = strtok(nullptr," ");
    while (p)
    {
        int index = 1;
        int num = stoi(p);
        while (tree[index] != 0)
        {
            if(num > tree[index])
                index = index*2+1;
            else
                index = index*2;
        }
        tree[index] = num;
        tree[0] = max(tree[0],index);
        p = strtok(nullptr," ");
    }
    int findnum;
    cin >> findnum;
    vector<int> in,pre,post;
    inorder(tree,findnum,1, in);
    preorder(tree,findnum,1,pre);
    postorder(tree,findnum,1,post);
    cout << *(find(in.begin(),in.end(),findnum)-1) << " "
         << *(find(pre.begin(),pre.end(),findnum)-1) << " "
         << *(find(post.begin(),post.end(),findnum)-1) << endl;
    return 0;
}