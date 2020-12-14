/*
unordered map
: 해시맵
해시테이블
중복불가능 (multimap가능)


map
: 균형트리
중복불가능 (multimap가능)
삽입되면서 자동정렬 (default : 오름차순)
Allocator-aware (동적할당)
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    
    for(int i=0;i<completion.size();i++)
    {
        m[completion[i]]+=1;
    }
    
   for(int i=0;i<participant.size();i++)
    {
        m[participant[i]]-=1;
        if(m[participant[i]]<0)
        {
            answer = participant[i];
            break;
        }
    }
        
    return answer;
}
