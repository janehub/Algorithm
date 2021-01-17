#include <string>
#include <vector>

using namespace std;

vector<int> v;
int tgt=0;
int g_answer=0;


void mk_pm(int idx,int sum)
{
    if(idx==v.size()){
     //   printf("%d\n",sum);
        if(sum==tgt){
            g_answer++;
        }
        return;
    }
    
   // printf("%d : + %d /",idx, v[idx]);
    mk_pm(idx+1,sum+v[idx]);
    
   // printf("%d : - %d /",idx, v[idx]);
    mk_pm(idx+1,sum-v[idx]);
}

int solution(vector<int> numbers, int target) {
    //int answer = 0;
    v=numbers;
    tgt=target;
    g_answer=0;
    
    mk_pm(0,0);
    
    return g_answer;
}
