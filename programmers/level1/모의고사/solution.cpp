#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnts[3]={0};    /* 수포자들 맞은 갯수 */
    int ans_1[5] = {1,2,3,4,5};  /* 1번 수포자 찍은정답 5개씩반복 */
    int ans_2[8] = {2, 1, 2, 3, 2, 4, 2, 5}; /*2번 수포자 찍은정답  8개씩반복*/
    int ans_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; /*3번 수포자 찍은정답  10개씩반복*/
    
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i]==ans_1[i%5])
            cnts[0]++;
        if(answers[i]==ans_2[i%8])
            cnts[1]++;
        if(answers[i]==ans_3[i%10])
            cnts[2]++;
    }
    
    answer.push_back(1);
    if(cnts[1]>cnts[answer.back()-1] )
    {
        answer.pop_back();
        answer.push_back(2);
    }
    else if(cnts[1]==cnts[answer.back()-1])
    {
        answer.push_back(2);
    }
    
    if(cnts[2]>cnts[answer.back()-1]  )
    {
        answer.pop_back();
        answer.push_back(3);
    }
    else if(cnts[2]==cnts[answer.back()-1])
    {
        answer.push_back(3);
    }
        
    
    /* 오름차순 정렬 */
    sort(answer.begin(),answer.end());
    
    return answer;
}
