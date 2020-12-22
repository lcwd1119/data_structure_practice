#include <iostream>
#include <cstring>
using namespace std;

struct treenode
{
    char data[500];
    treenode *rightptr;
    treenode *leftptr;
};

class tree
{
    treenode *rootptr;
public:
    tree()
    {
        rootptr = nullptr;
    }
    tree(char *input)
    {
        buildtree(input,rootptr);
    }
    void buildtree(char *str,treenode *&newnode)
    {
        if(strchr(str,'(') == nullptr)
        {
            newnode = new treenode;
            strcpy(newnode->data,str);
            newnode->leftptr = nullptr;
            newnode->rightptr = nullptr;
            return;
        }
        str[strlen(str)-2] = '\0';
        str += 2;
        char *p = strtok(str," ");
        newnode = new treenode;
        strcpy(newnode->data,p);
        p = strtok(nullptr," ");
        if(strcmp(p,"(") == 0)
        {
            char temp[100];
            strcpy(temp,"(");
            strcat(temp," ");
            p = strtok(nullptr," ");
            int tokcount = 0;
            while (tokcount != -1)
            {
                strcat(temp,p);
                strcat(temp," ");
                p = strtok(nullptr," ");
                if(strcmp(p,"(") == 0) tokcount++;
                if(strcmp(p,")") == 0) tokcount--;
            }
            strcat(temp,")");
            p += 2;
            buildtree(temp,newnode->leftptr);
            p = strtok(p," ");
        }
        else {
            buildtree(p, newnode->leftptr);
            p = strtok(nullptr, " ");
        }

        if(strcmp(p,"(") == 0)
        {
            char temp[100];
            strcpy(temp,"(");
            strcat(temp," ");
            p = strtok(nullptr," ");
            int tokcount = 0;
            while (tokcount != -1)
            {
                strcat(temp,p);
                strcat(temp," ");
                p = strtok(nullptr," ");
                if(strcmp(p,"(") == 0) tokcount++;
                if(strcmp(p,")") == 0) tokcount--;
            }
            strcat(temp,")");
            buildtree(temp,newnode->rightptr);
        }
        else
            buildtree(p,newnode->rightptr);
    }
    int calall(treenode *node)
    {
        if(node->data[0] >= '0' && node->data[0] <= '9')
            return stoi(node->data);

        if(strcmp(node->data,"+") == 0)
            return calall(node->leftptr) + calall(node->rightptr);
        else if(strcmp(node->data,"-") == 0)
            return calall(node->leftptr) - calall(node->rightptr);
        else if(strcmp(node->data,"*") == 0)
            return calall(node->leftptr) * calall(node->rightptr);
        else if(strcmp(node->data,"/") == 0)
            return calall(node->leftptr) / calall(node->rightptr);
    }
    int calall()
    {
        return calall(rootptr);
    }
};

int main()
{
    char fun[500];
    fgets(fun,500,stdin);
    strtok(fun,"\r\n");

    char variable[500];
    //fgets(variable,500,stdin);
    while (fgets(variable,500,stdin)) {
        char *p = strchr(fun,variable[0]);
        while (p) {
            *p = variable[4];
            p = strchr(fun, variable[0]);
        }
    }
    tree funtree(fun);
    cout << funtree.calall() << endl;
    return 0;
}