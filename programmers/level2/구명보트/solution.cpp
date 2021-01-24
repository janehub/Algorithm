#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    
    sort(people.begin(),people.end(), greater<int>());
    
    for(int i=0;i<people.size()-1;i++)
    {
        if(people[i]+people.back()<=limit)
        {
            people.pop_back();
            answer--;
        }
    }
    
    
    return answer;
}
