#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum=0;
    bool exist=false;
    
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            sum = numbers[i]+numbers[j];

            /* 이미 등록되어있는지 확인 */
            exist=false;
            for(int k=0;k<answer.size();k++){
                 if(answer[k] == sum){
                     exist=true;
                     break;
                 }                     
            }
            /* memorize */
            if(!exist)
                answer.push_back(sum);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}