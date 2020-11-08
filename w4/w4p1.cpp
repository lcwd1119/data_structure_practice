#include <iostream>

using namespace std;
int main()
{
    string sentence,target,change;
    getline(cin,sentence);
    cin >> target >> change;
    for (int i=0;i<sentence.size();i++)
    {
        bool isfind = false;
        if(sentence[i] == target[0])
        {
            isfind = true;
            for(int count = 0,j=i;count < target.size();j++,count++)
            {
                if(sentence[j] != target[count])
                {
                    isfind= false;
                    break;
                }
            }
        }

        if(isfind)
        {
            cout << change;
            i += target.size()-1;
            continue;
        }
        cout << sentence[i];
    }
    cout << endl;
    return 0;
}
