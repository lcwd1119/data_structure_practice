#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int size,goals;
    cin >> size >> goals;
    char matrix[size][size];
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            cin >> matrix[j][i];
        }
    }
    bool isexist = false;
    string horizonalstring,verticalstring,targetword;
    for(int t = 0;t < goals;t++)
    {
        cin >> targetword;
        for (int i = 0; i < size; i++)
        {
            horizonalstring = "";
            verticalstring = "";
            for (int j = 0; j < size; j++)
            {

                horizonalstring += matrix[i][j];
                verticalstring += matrix[j][i];
            }
            horizonalstring = horizonalstring + horizonalstring + horizonalstring;
            verticalstring = verticalstring + verticalstring + verticalstring;
            if(horizonalstring.find(targetword)!=-1 || verticalstring.find(targetword)!=-1)
            {
                isexist = true;
                break;
            }
            reverse(horizonalstring.begin(),horizonalstring.end());
            reverse(verticalstring.begin(),verticalstring.end());
            if(horizonalstring.find(targetword)!=-1 || verticalstring.find(targetword)!=-1)
            {
                isexist = true;
                break;
            }
        }
        if(isexist)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        targetword = "";
        isexist = false;
    }
    return 0;
}

