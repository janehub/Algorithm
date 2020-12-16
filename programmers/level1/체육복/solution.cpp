#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int left = 0;
    int right = 0;
    int cnt=0;  /*빌려준수*/
    
    bool chk[30]={false};   /* true: lost(체육복잃어버림), false: 체육복있음*/
 
    for(int c:lost)
    {
        chk[c-1] = true;
    }
    
    for(int i=0;i<reserve.size();)
    {
        int r_m1=reserve[i]-1;
        if(chk[r_m1]==true)
        {
            chk[r_m1]=false;
            reserve.erase(reserve.begin()+i);
            cnt++;
        }
        else
        {
            i++;
        }
    }
    
    for(int r:reserve)
    {
        int r_m1=r-1;
        left = r_m1-1;
        right = r_m1+1;

        if(left>=0&&chk[left]==true)
        {
            chk[left]=false;
            cnt++;
            continue;
        }
        else if(right<=n-1&&chk[right]==true)
        {
            chk[right]=false;
            cnt++;
            continue;
        }
    }
    
    answer = n-lost.size()+cnt;

    
    return answer;
}
