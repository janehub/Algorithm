/*
int 자료형 범위.
(A + B)%C = (A%C + B%C)%C
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fib_mod[100001];    //1234567로 나눈 나머지 값을 저장
    
    fib_mod[0]=0;
    fib_mod[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        fib_mod[i]=(fib_mod[i-1]+fib_mod[i-2])%1234567;
    }
    
   // cout<<fib[n];
    
    answer=fib_mod[n]%1234567;
    
    return answer;
}
