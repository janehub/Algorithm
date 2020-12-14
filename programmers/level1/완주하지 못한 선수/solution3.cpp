/*
auto : type inference

코드참고:
https://rooted.tistory.com/13
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    
    for(auto c:completion)
    {
        m[c]+=1;
    }
    
   for(auto p:participant)
    {
        m[p]-=1;
        if(m[p]<0)
        {
            answer = p;
            break;
        }
    }
        
    return answer;
}
