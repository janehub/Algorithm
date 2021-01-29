#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int sum=0;
    
    for(char c:s)
    {
        int chk=(c=='('?1:-1);
        
        sum+=chk;
        if(sum<0)
        {
            return false;
        }
    }
    
    if(sum!=0)
    {
        answer=false;
    }

    return answer;
}
