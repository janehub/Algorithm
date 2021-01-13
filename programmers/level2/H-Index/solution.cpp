#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    bool chk=false; //h번 이상 인용된 논문이 h편 이상 있는지 체크
    
    sort(citations.begin(),citations.end());
    
    //h:0~citations[citations.size()-1]
    for(int i=1;i<citations[citations.size()-1];i++)
    {
        chk=false;
        for(int j=0;j<citations.size();j++)
        {
            if(citations[j]>=i)
            {
                int p=citations.size()-j;//i번 이상인용된 편수
                if(p>=i)
                {
                    chk=true;
                }
                break;
            }
        }
        
        if(chk)
        {
            answer=i;
        }
        else
            break;
    }
    
    return answer;
}
