#include <iostream>
#include <vector>
using namespace std;
struct data{
    int dfn;
    int low;
};
vector<int> graph[100];
void cal(vector<int> &location,data arr[],int isvisit[],int lastindex,int index,int &num)
{
    arr[index].dfn = arr[index].low = num++;
    isvisit [index] = 1;
    int next;
    for(int i = 0;i < location.size();i++)
    {
        next = location[i];
        if(!isvisit[next])
        {
            cal(graph[next],arr,isvisit,index,next,num);
            if(arr[next].low < arr[index].low)
                arr[index].low = arr[next].low;
        }
        else if(next != lastindex) {
            if (arr[next].low < arr[index].low)
                arr[index].low = arr[next].low;
        }
    }
}
int main()
{
    int vertex1,vertex2,size = 0;
    while (cin >> vertex1 >> vertex2)
    {
        if(vertex1 == -1)
            break;
        size = max(max(vertex1,vertex2),size);
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    data arr[size+1];
    int isvisit[100] = {};
    int num = 0;
    cal(graph[3],arr,isvisit,3,3,num);
    cout << "    ";
    for(int i = 0;i < size+1;i++)
    {
        if(i != 0)
            cout << " ";
        cout << i;
    }
    cout << endl << "dfn ";
    for(int i = 0;i < size+1;i++)
    {
        if(i != 0)
            cout << " ";
        cout << arr[i].dfn;
    }
    cout << endl << "low ";
    for(int i = 0;i < size+1;i++)
    {
        if(i != 0)
            cout << " ";
        cout << arr[i].low;
    }
    cout << endl;
    return 0;
}