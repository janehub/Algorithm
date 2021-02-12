#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a.size()<b.size()?true:false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    
    //Parsing
    vector<int> vv;
    string tmp="";
    for(int i=1;i<s.length()-1;i++)
    {
        if(s[i]=='{')
        {
            vv.clear();
            continue;
        }
        else if(s[i]=='}')
        {
            vv.push_back(stoi(tmp));
            v.push_back(vv);
        }else if(s[i]==',')
        {
            vv.push_back(stoi(tmp));
            tmp="";
            continue;
        }else
        {
            tmp+=s[i];
        }
    }
    
    sort(v.begin(),v.end(),compare);
    
    answer.push_back(v[0][0]);
    for(int i=1;i<v.size();i++)
    {
        for(int a:v[i])
        {
            auto it = find(answer.begin(),answer.end(),a);
            if(it==answer.end())
                answer.push_back(a);
        }
    }
        
    return answer;
}
