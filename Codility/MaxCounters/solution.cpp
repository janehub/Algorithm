/*
Detected time complexity:
O(N*M)
*/
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> answer(N);

    for(int i=0;i<A.size();i++)
    {
        if(A[i]==N+1)
        {
            int max=*max_element(answer.begin(),answer.end());
            fill(answer.begin(),answer.end(),max);
        }else{
            answer[A[i]-1]++;
        }
    }

    return answer;
}
