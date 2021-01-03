#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.length();
    int cnt;//반복되는 횟수
    
    //자르는 단위
    for(int i=1;i<=s.length();i++)
    {
        int len=s.length();
        cnt=1;//반복되는 횟수
        string a=s.substr(0,i);
        for(int j=i;j<s.length();j+=i)
        {
            string b=s.substr(j,i);
            if(a.compare(b)==0){
                cnt++;
                len=len-i;
            }else{
                if(cnt>1){
                    len+=to_string(cnt).length();
                }
                cnt=1;
            }
            a=b;
        }
        
        if(cnt>1)
           len+=to_string(cnt).length();
        
        answer=min(answer,len);
    }
    
    return answer;
}
