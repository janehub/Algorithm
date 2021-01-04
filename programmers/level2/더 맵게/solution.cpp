#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    sort(scoville.begin(),scoville.end());
    
    for(int i=0;i<scoville.size()-1;i++){
        if(scoville[i]>=K){
            break;
        }else if(scoville[i]!=-1){
            scoville[i+1]=scoville[i]+scoville[i+1]*2;
            scoville[i]=-1;
            answer++;
            sort(scoville.begin(),scoville.end());
        }
    }
    
    if(scoville.back()<K)
        answer=-1;
        
    return answer;
}
