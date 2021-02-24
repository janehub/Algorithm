/*
Detected time complexity:
O(N*log(N)) or O(N)

*/

#include <unordered_map>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int,int> m;
    int answer=0;

    for(int a:A)
        m[a]++;

    for(auto iter=m.begin();iter!=m.end();iter++)
        answer++;

    return answer;

}
