#include <iostream>

using namespace std;
int main()
{
    int route[100][100] = {0},size = 0;
    int vertex1,vertex2,dist,start;
    cin >> start;
    while (cin >> vertex1 >> vertex2 >> dist)
    {
        if(vertex1 == -1)
            break;
        route[vertex1][vertex2] = dist;
        size = max(size,max(vertex1,vertex2));
    }
    int isused[100] = {0},mindist[100];
    for(int i = 0;i < size+1;i++) mindist[i] = 1000000;
    mindist[start] = 0;
    isused[start] = 1;
    for(int step = 1;step < size;step++)
    {
        //cout<<"step"<<step<<"\n";
        for(int from = 0;from < size+1;from++)
        {
            if(isused[from]==step) {
        //        cout<<"from"<<from<<endl;
                for (int to = 0; to < size + 1; to++) {
                    if (route[from][to] != 0) {
        //                cout<<"to"<<to<<"route[from][to]"<<route[from][to]<<endl;
                        if (mindist[to] > mindist[from] + route[from][to]) {
        //                    cout<<"dis"<<mindist[to]<<"change to";
                            mindist[to] = mindist[from] + route[from][to];
        //                    cout<<mindist[to]<<endl;
                            isused[to] = isused[from] + 1;
                            //change = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < size+1;i++)
    {
        cout << i << ": " << mindist[i] << endl;
    }
    return 0;
}