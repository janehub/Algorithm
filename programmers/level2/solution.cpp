#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt=0;  //출력갯수
    bool found=false;
    
    for(int i=0;i<priorities.size();i++)
    {
        found=false;
        for(int j=i+1;j<priorities.size();j++)
        {
            if(priorities[i]<priorities[j])
            {
                priorities.push_back(priorities[i]);
                if(i==location)
                {
                    location=priorities.size()-1;
                }
                found=true;

                break;
            }
        }
        
        if(!found)
        {
            //출력
            cnt++;
            if(i==location)
            {
                answer=cnt;
                return answer;
            }            
        }
    }
    
    return answer;
}
