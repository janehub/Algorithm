#include <string>
#include <vector>
#include <unordered_map>
//#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string,int> m;
    int cnt=1;

    
    for(auto clothe:clothes)
    {
        m[clothe[1]]+=1;
    }
    
    for(auto i=m.begin();i!=m.end();i++)
    {
        //cout<<i->first<<" "<<i->second<<endl;
        cnt*=(i->second+1);
    }
    
    //아무것도 입지 않는 경우 제거
    answer=cnt-1;
    
    return answer;
}
