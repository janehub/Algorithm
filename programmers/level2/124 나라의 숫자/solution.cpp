#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string digit[3]={"4","1","2"};
    
    while(n>0)
    {
        if(n%3==0)
        {
            answer.insert(0,digit[0]);
            n=n/3-1;
        }
        else
        {
            answer.insert(0,digit[n%3]);
            n=n/3;
        }
    }
    return answer;
}
