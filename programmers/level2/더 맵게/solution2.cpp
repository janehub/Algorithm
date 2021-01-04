/*
Heap : 최댓값, 최솟값
Priory_queue : logN
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int v:scoville)
        q.push(v);
    
    
    for(int i=0;i<scoville.size()-1;i++){
        int a= q.top();
        q.pop();
        int b= q.top();
        q.pop();
        
        if(a>=K){
            break;
        }else {
            q.push(a+b*2);
            answer++;
        }
    }
    
    if(q.top()<K)
        answer=-1;
        
    return answer;
}
