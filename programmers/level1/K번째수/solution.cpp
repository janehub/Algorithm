#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;  /* start부터 end까지 자른 수를 담음 */
    int start=0;
    int end=0;
    int k=0;
    
    for(auto c:commands)
    {
        v.clear();
        start = c[0]-1;
        end = c[1]-1;
        k=c[2]-1;
        v.assign(array.begin()+start, array.begin()+end+1);
        sort(v.begin(),v.end());
        answer.push_back(v[k]);
        
    }
    
    return answer;
}
