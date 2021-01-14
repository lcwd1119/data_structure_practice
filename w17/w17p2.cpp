#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int vertex1;
    int vertex2;
    int cost;
};
class graph
{
    vector<edge> edgecost;
    int vertexnum;
public:
    graph()
    {
        vertexnum = 0;
    }
    void add(edge input)
    {
        if(max(input.vertex1,input.vertex2) > vertexnum)
            vertexnum = max(input.vertex1,input.vertex2);
        edgecost.push_back(input);
    }
    void sortlist()
    {
        for(int i = 0;i < edgecost.size();i++)
        {
            int min = edgecost[i].vertex1;
            int min_index = i;
            for(int j = i;j < edgecost.size();j++)
            {
                if(edgecost[j].vertex1 < min)
                {
                    min = edgecost[j].vertex1;
                    min_index = j;
                }
            }
            swap(edgecost[i],edgecost[min_index]);
        }
        for(int i = 0;i < edgecost.size();i++)
        {
            int mincost = edgecost[i].cost;
            int min_index = i;
            for(int j = i;edgecost[j].vertex1 == edgecost[i].vertex1;j++)
            {
                if(edgecost[j].cost < mincost)
                {
                    mincost = edgecost[j].cost;
                    min_index = j;
                }
            }
            swap(edgecost[i],edgecost[min_index]);
        }
    }
    void setunion(int unionrelation[],int target,int src)
    {
        if(target > src)
            swap(target,src);
        if(unionrelation[src] != -1)
            setunion(unionrelation,target,unionrelation[src]);
        else
            unionrelation[src] = target;
    }
    int find(int unionrelation[],int src)
    {
        if(unionrelation[src] == -1)
            return src;
        else
            find(unionrelation,unionrelation[src]);
    }
    int findindex(int src)
    {
        int index = 0;
        while (edgecost[index].vertex1 != src)
            index++;
        return index;
    }
    void printmincost(int start)
    {
        int unionrelation[vertexnum+1];
        for(int i = 0;i < vertexnum+1;i++) unionrelation[i] = -1;
        sortlist();
        int linkedge = 0,index = 0,costcount = 0;
        index = findindex(start);
        while (linkedge < vertexnum)
        {
            if(index > edgecost.size())
            {
                index = findindex(start);
            }
            if(find(unionrelation,edgecost[index].vertex1) == find(unionrelation,edgecost[index].vertex2))
            {
                index++;
                continue;
            }
            printf("%d: <%d,%d>\n",linkedge+1,edgecost[index].vertex1,edgecost[index].vertex2);
            setunion(unionrelation,edgecost[index].vertex1,edgecost[index].vertex2);
            costcount += edgecost[index].cost;
            index = findindex(edgecost[index].vertex2);
            linkedge++;
        }
        cout << endl << "The cost of minimum spanning tree: " << costcount << endl;
    }
    void print()
    {
        for(auto &i : edgecost)
            cout << i.vertex1 << " " << i.vertex2 << " " << i.cost << endl;
    }
};

int main()
{
    graph minspannig;
    int vertex1,vertex2,cost,start;
    cin >> start;
    while(cin >> vertex1 >> vertex2 >> cost)
    {
        if (vertex1 == -1)
            break;
        minspannig.add({vertex1,vertex2,cost});
        minspannig.add({vertex2,vertex1,cost});
    }
    minspannig.printmincost(start);
    return 0;
}