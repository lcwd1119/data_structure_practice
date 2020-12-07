#include <iostream>
#include <cstring>
using namespace std;

struct treenode
{
    char data[100];
    treenode *rightptr;
    treenode *leftptr;
};

class tree
{
    treenode *root;
public:
    tree()
    {
        root = nullptr;
    }
    void buildtree(char *str,treenode *&node)
    {

    }

};

int main()
{
    char fun[100];
    fgets(fun,100,stdin);
    strtok(fun,"\r\n");

    char variable[100];
    fgets(variable,100,stdin);
    strtok(variable,"\r\n");


    return 0;
}