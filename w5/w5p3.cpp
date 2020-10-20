#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
    int x,y,data;
}axis;

int main()
{
    int raw,column;
    cin >> raw;
    cin >> column;
    int matrix[raw][column];
    vector<axis> ans;
    axis temp;
    for(int i = 0;i < raw;i++)
    {
        for(int j = 0;j< column;j++)
        {
            cin >> matrix[j][i];
            if(matrix[j][i]!=0)
            {
                temp = {i,j,matrix[j][i]};
                ans.push_back(temp);
            }
        }
    }
    cout << raw << " " << column << " " << ans.size() << endl;
    for(int i = 0;i < ans.size();i++)
    {
        printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].data);
    }
    return 0;
}