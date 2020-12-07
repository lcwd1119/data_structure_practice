#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main()
{
    string prefix,suffix;
    cin >> prefix >> suffix;
    int charfrequency,wordfrequency;
    cin >> charfrequency >> wordfrequency;
    getchar();
    string sentence;
    getline(cin,sentence,'\r');

    int temp = 0;
    set<string> prefixes;
    while (sentence.find(prefix,temp) < sentence.size()) {
        string str = "";
        temp = sentence.find(prefix,temp);
        if(sentence[temp-1] != ' ')
        {
            temp+= prefix.size();
            continue;
        }
        while (sentence[temp] != ' ' && temp < sentence.size()) {
            str += sentence[temp];
            if(temp >= sentence.size())
                break;
            temp++;
        }
        prefixes.insert(str);
    }
    cout << "prefix of " << prefix << ':' << endl;
    for(auto it = prefixes.begin();it != prefixes.end();it++)
        cout << *it << endl;


    set<string> suffixes;
    temp = 0;
    while (sentence.find(suffix,temp) < sentence.size()) {
        string str = "";
        temp = sentence.find(suffix,temp);
        if(sentence[temp+suffix.size()] != ' ')
        {
            temp += suffix.size();
            continue;
        }
        while (sentence[temp] != ' ')
            temp--;
        temp++;
        while (sentence[temp] != ' ' && temp < sentence.size()) {
            str += sentence[temp];
            if(temp >= sentence.size())
                break;
            temp++;
        }
        suffixes.insert(str);
    }
    cout << "suffix of " << suffix << ':' << endl;
    for(auto it = suffixes.begin();it != suffixes.end();it++)
        cout << *it << endl;

    int charcount[26] = {0};
    for(int i = 0;i < sentence.size();i++)
        charcount[sentence[i] - 'a']++;

    cout << "character frequency over " << charfrequency << ':' << endl;
    for(int i =0;i < 26;i++)
        if(charcount[i] >= charfrequency)
            printf("%c,%d\n",i+'a',charcount[i]);

     map<string,int> wordcount;
     set<string> wordset;
     string tempword;
     for(int i = 0;i < sentence.size();i++)
     {
         if(sentence[i] == ' ')
         {
             auto isfind = wordcount.find(tempword);
             if(isfind == wordcount.end()) {
                 wordset.insert(tempword);
                 wordcount[tempword] = 1;
             }
             else
                 wordcount[tempword]++;
             tempword = "";
             continue;
         }
         tempword += sentence[i];
     }
    cout << "word frequency over " << wordfrequency << ':' << endl;
     for(auto it = wordset.begin();it != wordset.end();it++)
     {
         auto iter = wordcount.find(*it);
         if(iter->second >= wordfrequency)
             cout << *it << ',' << iter->second << endl;
     }
    return 0;
}