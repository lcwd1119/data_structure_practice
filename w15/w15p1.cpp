#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num1,num2;
    int matrix_size = 0;
    int adjacency_matrix[100][100] = {0};
    vector<int> adjacency_list[100];
    while (cin >> num1 >> num2)
    {
        if(max(num1,num2) > matrix_size)
            matrix_size = max(num1,num2);
        adjacency_matrix[num1][num2] = adjacency_matrix[num2][num1] = 1;
        adjacency_list[num1].push_back(num2);
        adjacency_list[num2].push_back(num1);
    }
    cout << "Adjacency matrix:" << endl;
    for(int i = 0;i <= matrix_size;i++)
    {
        for(int j = 0;j <= matrix_size;j++)
        {
            cout << adjacency_matrix[j][i];
            if (j != matrix_size)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << "Adjacency list:" << endl;
    for(int i = 0;i <= matrix_size;i++)
    {
        cout << i << ":";
        for(int j = 0;j < adjacency_list[i].size();j++)
            cout << " " << adjacency_list[i][j] << " ->";
        cout << " end" << endl;
    }
    return 0;
}