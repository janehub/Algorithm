#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    sort(friends,friends+8);
    
    do{
        bool flag=true;
        for(int i=0;i<data.size();i++)
        {
            char a=data[i][0];
            char b=data[i][2];
            char op=data[i][3]; //=, <, >
            int dis=data[i][4]-'0';
            dis+=1;
            
            char* idx_a=find(friends,friends+8,a);
            char* idx_b=find(friends,friends+8,b);
            
            if(op=='=')
            {
                if(abs(idx_a-idx_b)!=dis)   //만족하지않음
                {
                    flag=false;
                    break;
                }
            }else if(op=='<')
            {
                if(abs(idx_a-idx_b)>=dis)   //만족하지않음
                {
                    flag=false;
                    break;
                }
            }else
            {
                 if(abs(idx_a-idx_b)<=dis)   //만족하지않음
                {
                    flag=false;
                    break;
                }
            } 
        }
        if(flag)
            answer++;
    }while(next_permutation(friends,friends+8));
    
    
    return answer;
}
