#include <iostream>
#include <algorithm>
using namespace std;

void setunion(int arr[],int size,int num1,int num2)
{
    if(arr[num1] == arr[num2] && arr[num1] == -1)
    {
        int min = num1;
        if(num2 < min)
            min = num2;
        arr[num1] = min;
        arr[num2] = min;
    }
    else if(arr[num1] == -1 || arr[num2] == -1)
    {
        if(arr[num1] == -1)
            arr[num1] = arr[num2];
        else
            arr[num2] = arr[num1];
    }
    else
    {
        int union1 = arr[num1],union2 = arr[num2],min = union1;
        if(union2 < min)
            min = union2;
        for(int i = 0;i < size;i++)
            if(arr[i] == union1 || arr[i] == union2)
                arr[i] = min;
    }
}

void print_union(int arr[],int size)
{
    for(int i = 0; i < size;i++)
    {
        if(arr[i] == -1)
            printf(" {%d}",i);
        else
        {
            if(i > arr[i])
                continue;
            printf(" {%d",i);
            for(int j = i+1;j < size;j++)
            {
                if(arr[j] == arr[i])
                    printf(",%d",j);
            }
            printf("}");
        }
    }
    cout << endl;
}

bool find(int arr[],int size,int num1,int num2)
{
    if(arr[num1] == arr[num2] && arr[num1] != -1)
        return true;
    return false;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0;i < size;i++)
        arr[i] = -1;
    while (true)
    {
        int num1,num2;
        if(scanf("Union(%d,%d)",&num1,&num2))
        {
            printf("Union(%d,%d):",num1,num2);
            setunion(arr,size,num1,num2);
            print_union(arr,size);
        }
        else if(scanf("Find(%d), Find(%d)",&num1,&num2))
        {
            printf("Find(%d), Find(%d): ",num1,num2);
            if(find(arr,size,num1,num2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if(scanf("%d",&num1))
            break;
    }
    return 0;
}