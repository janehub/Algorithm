#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int f_idx=0;    //skill 인덱스
    bool learned[26];      //선행스킬 배웠는지 체크
    
    for(string s:skill_trees)
    {
        fill_n(learned,26,false);   //배열 초기화
        answer++;
        for(char c:s)
        {
            f_idx=skill.find(c);
            if(f_idx!=-1)    //선행스킬요구하는 스킬일 경우
            {
                if(f_idx==0)
                {
                    learned[0]=true;
                }else
                {
                    if(learned[f_idx-1]!=true)  //선행스킬배우지 않았을 경우
                    {
                        answer--;
                        break;
                    }
                    else
                    {
                        learned[f_idx]=true;
                    }
                }
            }
        }
    }
    
    return answer;
}
