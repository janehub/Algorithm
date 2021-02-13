#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cntOne(int n)
{
    int one=0;
    while(n){
        //cout<<n%2;
        if(n%2==1)
            one++;
        n=n/2;
    }
    
    return one;
}

int solution(int n) {
    int answer = 0;
    
    int rq_one=cntOne(n);
    //cout<<rq_one;
    
    while(1){
        n++;
        if(cntOne(n)==rq_one){
            answer=n;
            break;
        }
    }
    
    return answer;
}
