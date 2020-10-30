#include <iostream>
#define max_size 100
using namespace std;

typedef struct
{
    int x;
    int y;

}point;
point offsets[4] = {{1,0},
                    {0,-1},
                    {-1,0},
                    {0,1}};

class Stack
{
    point data[max_size];
    int top;
public:

    Stack()
    {
        top=-1;
    }
    bool isfull(){
        if (top == max_size - 1)
            return true;
        return false;
    }
    bool isempty(){
        if(top == -1)
            return true;
        return false;
    }
    bool push(point num){
        if (isfull())
            return false;
        top++;
        data[top] = num;
        return true;
    }
    bool pop(point &num){
        if(isempty())
            return false;
        num = data[top];
        top--;
        return true;
    }
};

int main()
{
    Stack moved;
    char maze[10][10];
    for(int i = 0;i < 10;i++) {
        for (int j = 0; j < 10; j++) {
            cin >> maze[i][j];
        }
    }
    point position = {8,8};
    maze[8][8] = 'S';
    while (1)
    {
        bool ismove = false;
        for(auto & offset : offsets)
        {
            if(maze[position.y+offset.y][position.x+offset.x] == '0')
            {
                moved.push(position);
                position.x = position.x + offset.x;
                position.y = position.y + offset.y;
                if (maze[position.y][position.x] == '0')
                    maze[position.y][position.x] = 'G';
                ismove = true;
                break;
            }
        }
        if(!ismove)
        {
            if (position.x == 1 && position.y == 1)
            {
                cout << "YES" << endl;
                break;
            }
            maze[position.y][position.x] = 'D';
            if(!moved.pop(position))
            {
                cout << "NO" << endl;
                break;;
            }
        }
    }
    maze[1][1] = 'X';
    for(int i = 0;i < 10;i++) {
        for (int j = 0; j < 10; j++) {
            cout << maze[i][j];
            if(j < 9)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}