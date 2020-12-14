/*
*****set
: 노드 기반 컨테이너, 균형이진트리
key(원소)집합
중복허용하지않음
삽입시 원소 자동정렬 (default : 오름차순)
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum=0;
    set<int> memo;
    
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            sum = numbers[i]+numbers[j];

            memo.insert(sum);

        }
    }
    
    answer.assign(memo.begin(),memo.end());
    
    return answer;
}
