#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int dpm[12]={31,29,31,30,31,30,31,31,30,31,30,31}; /* 월별 날짜수 */
    int base = 5; /* 2016년 1월 1일 FRI*/
    
    int cnt=0; /* 2016년 a월 b일 - 2016년 1월 1일*/
    
    cnt +=b-1;
    
    for(int i=(a-1)-1;i>=0;i--)
    {
        cnt+=dpm[i];
    }
    
    answer = day[(cnt+base)%7];
    
    return answer;
}
