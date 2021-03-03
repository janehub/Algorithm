#include <string>
#include <vector>

using namespace std;

bool isUpperCase(char c)
{
    return ('A'<=c)&&(c<='Z')?true:false;
}
string solution(string s) {
    string answer = "";
    bool isFirst;       //단어의 첫번째 문자인지 체크
    
    isFirst=true;
    for(char c: s)
    {
        if(c==' ')
        {
            isFirst=true;
            answer+=c;
            continue;
        }
        if(isFirst)
        {   
            if('0'<=c&&c<='9')
            {
                answer+=c;
            }else{
                if(!isUpperCase(c))
                {
                    answer+=(c-'a')+'A';
                }else{
                    answer+=c;
                }
            }
            isFirst=false;
        }else{
            if(isUpperCase(c))
                answer+=(c-'A')+'a';
            else
                answer+=c;
        }
    }
    
    //answer=answer.substr(0,answer.size()-1);
    
    return answer;
}
