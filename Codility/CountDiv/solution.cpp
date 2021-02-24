/*
0일때 예외값 처리 해주기
*/
#include <math.h>

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int answer=0;

    if(A==0)
        if(B==0)
            answer=1;
        else
            answer=B/K+1;
    else
        answer=B/K-ceil(A/(double)K)+1;

    return answer;
}
