#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int> > m;

char numbering(string s)
{
    if(s=="cpp"||s=="backend"||s=="junior"||s=="chicken")
        return '1';
    else if(s=="java"||s=="frontend"||s=="senior"||s=="pizza")
        return '2';
    else if(s=="python")
        return '3';
    else
        return 'x';
}

void permutation(string n,int depth,int score)
{
    if(depth==4)
    {
        m[n].push_back(score);
        return;
    }
    permutation(n,depth+1,score);
    n[depth]='x';
    permutation(n,depth+1,score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    //Parsing & mapping - info
    for(string s:info)
    {
        string tmp="";
        string num="";
        for(char c : s)
        {
            if(c==' ')
            {
                num+=numbering(tmp);
                tmp="";
            }
            else
            {
                tmp+=c;
            }
                
        }
        permutation(num,0,stoi(tmp));
    }
    
    for(auto iter=m.begin();iter!=m.end();iter++)
        sort(iter->second.begin(),iter->second.end());

    //Parsing -query
    for(int i=0;i<query.size();i++)
    {
        string tmp="";
        string num="";
        for(char c:query[i])
        {
            if(c==' ')
            {
                if(tmp!="and")
                {
                    char nn = numbering(tmp);
                    num+=nn;
                }
                tmp="";
            }else
            {
                tmp+=c;
            }
        }
        //연산
        vector<int> v = m[num];
        if(v.size()!=0)
        {
            auto it=lower_bound(v.begin(),v.end(),stoi(tmp));
            answer.push_back(v.size()-(it-v.begin()));
        }else{
            answer.push_back(0);
        }
    }
    
    return answer;
}
