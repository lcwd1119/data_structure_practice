#include <iostream>
#include <vector>
using namespace std;
struct edge
{
    int vertex;
    int cost;
};
int main()
{
    vector<edge> graph[100];
    int vertex1,vertex2,cost,size = 0;
    while (cin >> vertex1 >> vertex2 >> cost)
    {
        if(vertex1 == -1)
            break;
        size = max(max(vertex1,vertex2),size);
        graph[vertex1].push_back({vertex2,cost});
    }
    int dist[size+1],disttmp[size+1];
    for(int i = 0;i < size+1;i++)
        dist[i] = disttmp[i] = 99999;
    dist[0] = disttmp[0] = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size+1; j++)
        {
            if(dist[j] == 99999)
                continue;
            for(int k = 0;k < graph[j].size();k++)
            {
                if (i == 0)
                    disttmp[graph[j][k].vertex] = graph[j][k].cost;
                else {
                    if(dist[j] == 99999)
                        continue;
                    disttmp[graph[j][k].vertex] = min(disttmp[graph[j][k].vertex],dist[j] + graph[j][k].cost);
                }
            }
        }
        for(int j = 0;j < size+1;j++)
            dist[j] = min(disttmp[j],dist[j]);
        for(int j = 0;j < size+1;j++)
        {
            if(j != 0)
                cout << " ";
            if(dist[j] == 99999)
                cout << "i";
            else
                cout << dist[j];
        }
        cout << endl;
    }
    return 0;
}