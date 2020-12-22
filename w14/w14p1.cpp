#include <iostream>
#include <cstring>
using namespace std;

class binTree
{
    struct node
    {
        node *leftptr;
        int data;
        node *rightptr;
    };
    node *root;
public:
    binTree()
    {
        root = nullptr;
    }
    void add(int input)
    {
        add(root,input);
    }
    void add(node *&treenode,int input)
    {
        if(!treenode)
        {
            treenode = new node;
            treenode->data = input;
            treenode->leftptr = nullptr;
            treenode->rightptr = nullptr;
            return;
        }
        if(input > treenode->data)
            add(treenode->rightptr,input);
        if(input < treenode->data)
            add(treenode->leftptr,input);
    }
    void preorder()
    {
        preorder(root);
        cout << endl;
    }
    void preorder(node *treenode)
    {
        if(treenode)
        {
            cout << treenode->data << " ";
            preorder(treenode->leftptr);
            preorder(treenode->rightptr);
        }
    }
};

int main()
{
    char input[500];
    binTree tree;
    fgets(input,500,stdin);
    strtok(input,"\r\n");
    char *p = strtok(input," ");
    while (p)
    {
        tree.add(stoi(p));
        tree.preorder();
        p = strtok(nullptr," ");
    }
    return 0;
}