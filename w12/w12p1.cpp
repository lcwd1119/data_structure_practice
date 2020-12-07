#include <iostream>
using namespace std;

int main()
{
    int total,index = 1;
    cin >> total;
    int treearr[100] = {0};
    for(;index <= 3;index++)
        cin >> treearr[index];
    while (true)
    {
        int node,left,right;
        cin >> node;
        if(node == -1)
            break;
        for(int i = 1;;i++)
        {
            if(treearr[i] == node) {
                index = i;
                break;
            }
        }
        cin >> left >> right;
        index *= 2;
        treearr[index] = left;
        index++;
        treearr[index] = right;
        treearr[0] = index;
    }
    while (treearr[treearr[0]] == 0)
        treearr[0]--;
    for(int i = 1;i < treearr[0];i++)
        cout << treearr[i] << " ";
    cout << treearr[index] << endl;
    return 0;
}