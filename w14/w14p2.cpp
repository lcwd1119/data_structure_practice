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

    void preorder(node *treenode)
    {
        if(treenode)
        {
            cout << treenode->data << " ";
            preorder(treenode->leftptr);
            preorder(treenode->rightptr);
        }
    }

    bool find(int input,node *&locaton,node **&locationupper)
    {
        node *index = root;
        locationupper = &root;
        while (index)
        {
            if(input == index->data)
            {
                locaton = index;
                return true;
            }
            else if(input > index->data)
            {
                locationupper = &index->rightptr;
                index = index->rightptr;
            }
            else
            {
                locationupper = &index->leftptr;
                index = index->leftptr;
            }
        }
        locationupper = nullptr;
        return false;
    }
    int finmax(node *location)
    {
        while (location->rightptr != nullptr)
            location = location->rightptr;
        return location->data;
    }
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

    void del(int input)
    {
        node *target,**upper;
        if(!find(input,target,upper))
        {
            cout << "no " << input << endl;
            return;
        }

        if(target->leftptr == nullptr && target->rightptr == nullptr)
        {
            *upper = nullptr;
            delete target;
        }
        else if(target->leftptr != nullptr && target->rightptr != nullptr)
        {
            int max = finmax(target->leftptr);
            del(max);
            target->data = max;
        }
        else
        {
            if(target->leftptr != nullptr)
                *upper = target->leftptr;
            else
                *upper = target->rightptr;
            delete target;
        }
    }
    void preorder()
    {
        preorder(root);
        cout << endl;
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
        p = strtok(nullptr," ");
    }
    cout << "Binary search tree (before):" << endl;
    tree.preorder();

    fgets(input,500,stdin);
    strtok(input,"\r\n");
    p = strtok(input," ");
    while (p)
    {
        int a = stoi(p);
        tree.del(a);
        p = strtok(nullptr," ");
    }
    cout << "Binary search tree (after):" << endl;
    tree.preorder();
    return 0;
}