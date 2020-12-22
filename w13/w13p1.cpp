#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

struct treenode{
    string data;
    int level;
    treenode *leftptr;
    treenode *rightptr;
};

class Tree
{
    treenode *rootptr;
public:
    Tree()
    {
        rootptr = nullptr;
    }

    void choosepos(treenode *&node,string input)
    {
        if(input[input.size()-1] % 2 == 1)
            setdata(node->leftptr,input,node->level);
        else
            setdata(node->rightptr,input,node->level);
    }

    void setdata(treenode *&node,string input,int upperlevel)
    {
        node = new treenode;
        node->data = input;
        node->leftptr = nullptr;
        node->rightptr = nullptr;
        node->level = upperlevel+1;
    }

    void addnode(treenode *&node,string target,string input1 = "",string input2 = "")
    {
        if(rootptr == nullptr)
        {
            setdata(rootptr,target,0);
            if(input1 != "")
                choosepos(rootptr,input1);
            if(input2 != "")
                choosepos(rootptr,input2);
        }

        if(node == nullptr)
            return;

        if(node->data == target)
        {
            if(input1 != "")
                choosepos(node,input1);
            if(input2 != "")
                choosepos(node,input2);
        }

        addnode(node->leftptr,target,input1,input2);
        addnode(node->rightptr,target,input1,input2);
    }

    void addval(string target,string input1 = "",string input2 = "")
    {
        addnode(rootptr,target,input1,input2);
    }
    void preorder(treenode *node)
    {
        if(node)
        {
            cout << node->data << " ";
            preorder(node->leftptr);
            preorder(node->rightptr);
        }
    }

    void inorder(treenode *node)
    {
        if(node)
        {
            inorder(node->leftptr);
            cout << node->data << " ";
            inorder(node->rightptr);
        }
    }

    void postorder(treenode *node)
    {
        if(node)
        {
            postorder(node->leftptr);
            postorder(node->rightptr);
            cout << node->data << " ";
        }
    }

    void calbalancefactor(treenode *node,int &maxdepth)
    {
        if(node)
        {
            if(node->level > maxdepth)
                maxdepth = node->level;
            calbalancefactor(node->leftptr,maxdepth);
            calbalancefactor(node->rightptr,maxdepth);
        }
    }

    void print()
    {
        cout << "Preorder: ";
        preorder(rootptr);
        cout << endl;
        cout << "Inorder: ";
        inorder(rootptr);
        cout << endl;
        cout << "Postorder: ";
        postorder(rootptr);
        cout << endl;
        int ldepth = 0,rdepth = 0;
        calbalancefactor(rootptr->leftptr,ldepth);
        calbalancefactor(rootptr->rightptr,rdepth);
        cout << "The balance factor is " << abs(ldepth-rdepth) << endl;

    }
};

int main()
{
    Tree tree;
    char input[100];
    while (strcmp(input,"0") != 0) {
        fgets(input, 100, stdin);
        strtok(input, "\r\n");
        char *p = strtok(input," ");
        int i = 0;
        string data[3];
        while (p)
        {
            data[i] = p;
            p = strtok(nullptr," ");
            i++;
        }
        if(i == 2)
            tree.addval(data[0],data[1]);
        else
            tree.addval(data[0],data[1],data[2]);
    }
    tree.print();
    return 0;
}