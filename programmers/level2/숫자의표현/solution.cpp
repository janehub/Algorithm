#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            //i~j까지 더하기
            int sum=(j*(j+1)-(i-1)*i)/2;
            if(sum==n)
            {
                //cout<<i<<" "<<j<<endl;
                answer++;
                break;
            }else if(sum>n)
                break;
        }
    }
    
    answer++;   //n자신
    
    return answer;
}
