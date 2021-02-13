#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toBinary(int n)
{
    string s="";
    while(n)
    {
        s=s+to_string(n%2);
        n=n/2;
    }
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int rm0=0;
    int bin_cnt=0;
    
    while(s!="1")
    {
        string tmp="";
        for(auto c:s)
        {
            if(c=='0')
                rm0++;
            else
                tmp+=c;
        }

        //cout<<tmp<<" "<<rm0<<endl;
        s=toBinary(tmp.size());
        bin_cnt++;
    }
    
    answer.push_back(bin_cnt);
    answer.push_back(rm0);

    return answer;
}
