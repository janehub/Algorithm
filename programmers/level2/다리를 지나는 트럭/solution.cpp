#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum=0;  //다리를 건너는 트럭들의 합
    queue<int> twOnB; //다리를 건너는 트럭들
    
    //초기화
    for(int i=0;i<bridge_length;i++)
    {
        twOnB.push(0);
    }
    
    for(int i=0;i<truck_weights.size();)
    {
        //맨 앞 트럭 이동
        sum-=twOnB.front();
        twOnB.pop();
        
        //무게 체크
        if(sum+truck_weights[i]<=weight)
        {
            //다리를 건너는 트럭
            twOnB.push(truck_weights[i]);
            sum+=truck_weights[i];
            i++;
        }
        else
        {
            twOnB.push(0);
        }
        //시간 경과
        answer++;
    }
    
    //다리를 마지막까지 건너는데 필요한 
    answer+=bridge_length;
    
    return answer;
}
