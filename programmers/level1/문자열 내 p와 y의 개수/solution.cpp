#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt=0;
    
    for(char c:s)
    {
        if(c=='p'||c=='P')
            cnt++;
        else if(c=='y'||c=='Y')
            cnt--;
    }
    
    answer=cnt==0?true:false;

    return answer;
}
