#include <string>
#include <vector>

/**
정수/정수 -> 정수
double로 형변환한 다음 ceil 적용
*/
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remain_date;
    const int FINISH=100;
    int d_cnt=0;    //경과 시간
    
    //남은 작업일수 계산
    for(int i=0;i<progresses.size();i++)
    {
        int d=ceil((FINISH-progresses[i])/(double)speeds[i]);
        remain_date.push(d);        
    }
    
    int k=-1;
    while(!remain_date.empty())
    {
        if(remain_date.front()<=d_cnt)   // 같이 배포
        {
            answer[k]++;
        }
        else
        {
            answer.push_back(1);
            k++;
            d_cnt=remain_date.front();
        }
        remain_date.pop();
    }
    
    return answer;
}
