#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> answer;
multimap<string,int> m;

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

void permutation(string n,int depth,int score,int k)
{
    if(depth==4)
    {
        //cout<<n<<"&&"<<score<<endl;
        //연산
       for(auto iter=m.lower_bound(n);iter!=m.upper_bound(n);iter++)
       {
         if(iter->second>=score)
         {
             answer[k]++;
             //cout<<"found"<<endl;  
         }          
       }

          return;
    }
    
    if(n[depth]=='x')
    {
        if(depth==0)    //1,2,3
        {
            n[depth]='1';
            permutation(n,depth,score,k);
            n[depth]='2';
            permutation(n,depth,score,k);
            n[depth]='3';
            permutation(n,depth,score,k);
        }else{          //1,2
            n[depth]='1';
            permutation(n,depth,score,k);
            n[depth]='2';
            permutation(n,depth,score,k);
        }
    }else{
        permutation(n,++depth,score,k);
    }
    
}

vector<int> solution(vector<string> info, vector<string> query) {
    answer.clear();
    m.clear();
    
    //Parsing & mapping - info
    for(string s:info)
    {
        string tmp="";
        string num="";
        for(char c : s)
        {
            if(c==' ')
            {
                //cout<<"*"<<tmp<<endl;
                //cout<<"**"<<numbering(tmp)<<endl;
                num+=numbering(tmp);
                tmp="";
            }
            else
            {
                tmp+=c;
            }
                
        }
        //cout<<"@"<<num<<endl;
        //cout<<"*"<<tmp<<endl;
        m.insert(pair<string,int>(num,stoi(tmp)));
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
        //cout<<"***"<<num<<endl;
        answer.push_back(0);
        permutation(num,0,stoi(tmp),i);
    }
    
    return answer;
}
