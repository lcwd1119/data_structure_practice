#include <iostream>
using namespace std;

int main()
{
    char input1,input2;
    int graph[26];
    for(int i = 0;i < 26;i++)
        graph[i] = -1;
    char firstchar = 'z';
    int edgenum = 0;
    while (cin >> input1 >> input2)
    {
        if(input1 == '-')
            break;
        firstchar = min(min(input1,input2),firstchar);
        if(graph[input1-'a'] == -1 && graph[input2-'a'] == -1)
            graph[min(input1-'a',input2-'a')] = max(input1-'a',input2-'a');
        else if(graph[input1 - 'a'] == -1)
                graph[input1 - 'a'] = input2-'a';
        else if(graph[input2 - 'a'] == -1)
                graph[input2-'a'] = input1-'a';
        edgenum++;
    }
    int index = firstchar-'a',edgecount = 0;
    while (true)
    {
        if(graph[index] == -1)
            break;
        index = graph[index];
        edgecount++;
    }
    if(edgecount == edgenum)
        cout << firstchar << " " << char(index+'a') << endl;
    else
        cout << "null" << endl;
    return 0;
}