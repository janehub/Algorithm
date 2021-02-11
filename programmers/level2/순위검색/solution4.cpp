#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> m;

void permutation(vector<string> key, int score,int depth)
{
    if(depth==4)
    {
        string s=key[0]+key[1]+key[2]+key[3];
        m[s].push_back(score);
        //cout<<s<<score<<endl;
        return;
    }
    
    permutation(key,score,depth+1);
    key[depth]="-";
    permutation(key,score,depth+1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> key(4);
    string bin;
    int score;
    m.clear();
    
    for(string s:info)
    {
        istringstream iss(s);
        iss>>key[0]>>key[1]>>key[2]>>key[3]>>score;
        permutation(key,score,0);
    }
    
    for(auto iter=m.begin();iter!=m.end();iter++)
        sort(iter->second.begin(),iter->second.end());
    
    for(string q:query)
    {
        istringstream iss(q);
        iss>>key[0]>>bin>>key[1]>>bin>>key[2]>>bin>>key[3]>>score;
        vector<int> v = m[key[0]+key[1]+key[2]+key[3]];
        if(v.size()>0)
        {
            auto it = lower_bound(v.begin(),v.end(),score);
             answer.push_back(v.size()-(it-v.begin()));
        }else
        {
            answer.push_back(0);
        }
    }
    
    
    return answer;
}
