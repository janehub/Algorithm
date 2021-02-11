#include <string>
#include <vector>
#include<map>
#include<set>
#include <iostream>
#include <algorithm>

using namespace std;

multiset<pair<string, int>> b;

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
        b.insert(pair<string, int>(n, score));
        return;
    }
    
    permutation(n,depth+1,score);
    n[depth]='x';
    permutation(n,depth+1,score);
    
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    multimap<string,int> um;
    b.clear();
    
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
    
     for(auto iter = b.rbegin(); iter != b.rend(); iter++){
         um.insert(pair<string,int>(iter->first,iter->second));
     }
    
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
        answer.push_back(0);
       // cout<<i<<" : "<<num<<"&&"<<stoi(tmp)<<endl;
        for(auto iter=um.lower_bound(num);iter!=um.upper_bound(num);iter++)
        {
            //cout<<iter->first<<"&&"<<iter->second<<endl;
            if(iter->second>=stoi(tmp))
            {
                answer[answer.size()-1]++;
                //cout<<iter->first<<"&&"<<iter->second<<endl;
            }
            else{
                break;
            }
        }
    }
    
    return answer;
}
