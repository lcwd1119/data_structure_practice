#include <iostream>
#include <map>
using namespace std;

int main()
{
    string prefix,suffix;
    cin >> prefix >> suffix;
    int charfrequency,wordfrequency;
    cin >> charfrequency >> wordfrequency;
    getchar();
    getchar();
    string sentence;
    getline(cin,sentence);
    int temp = 0;
    cout << "prefix of " << prefix << ':' << endl;
    while (sentence.find(prefix,temp) < sentence.size()) {
        temp = sentence.find(prefix,temp);
        if(sentence[temp-1] != ' ')
        {
            temp+= prefix.size();
            continue;
        }
        while (sentence[temp] != ' ') {
            cout << sentence[temp];
            if(temp >= sentence.size())
                break;
            temp++;
        }
        cout << endl;
    }

    cout << "suffix of " << suffix << ':' << endl;
    temp = 0;
    while (sentence.find(suffix,temp) < sentence.size()) {
        temp = sentence.find(suffix,temp);
        if(sentence[temp+suffix.size()] != ' ')
        {
            temp += suffix.size();
            continue;
        }
        while (sentence[temp] != ' ')
            temp--;
        temp++;
        while (sentence[temp] != ' ') {
            cout << sentence[temp];
            if(temp >= sentence.size())
                break;
            temp++;
        }
        cout << endl;
    }

    int charcount[26] = {0};
    for(int i = 0;i < sentence.size();i++)
        charcount[sentence[i] - 'a']++;

    cout << "character frequency over " << charfrequency << ':' << endl;
    for(int i =0;i < 26;i++)
        if(charcount[i] >= charfrequency)
            printf("%c,%d\n",i+'a',charcount[i]);

     map<string,int> wordcount;
     string tempword;
     for(int i = 0;i < sentence.size();i++)
     {
         if(sentence[i] == ' ')
         {
             auto isfind = wordcount.find(tempword);
             if(isfind == wordcount.end())
                 wordcount[tempword] = 1;
             else
                 wordcount[tempword]++;
             tempword = "";
             continue;
         }
         tempword += sentence[i];
     }
    cout << "word frequency over " << wordfrequency << ':' << endl;
     for(auto iter = wordcount.begin();iter != wordcount.end();iter++)
     {
         if(iter->second >= wordfrequency)
             cout << iter->first << ',' << iter->second << endl;
     }
    return 0;
}