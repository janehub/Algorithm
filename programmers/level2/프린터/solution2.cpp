#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;   //인덱스 저장
    int cnt=0;  //출력갯수
    
    for(int i=0;i<priorities.size();i++)
    {
        q.push(i);
    }
    
    while(!q.empty())
    {
        int idx=q.front();
        q.pop();
        if(priorities[idx]!=*max_element(priorities.begin(),priorities.end()))
        {
            q.push(idx);
        }
        else
        {
            priorities[idx]=0;
            cnt++;
            if(idx==location)
            {
                return cnt;
            }
        }
    }
    
    return answer;
}
