/*
Detected time complexity:
O(N + M)
*/

#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> answer(N);
    int max_el=0;
    int last_max=0;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]==N+1)
        {
            last_max=max_el;
        }else{
            if(answer[A[i]-1]<last_max)
            {
                answer[A[i]-1]=last_max+1;
            }else{
                answer[A[i]-1]++;
            }

            max_el=max_el<answer[A[i]-1]?answer[A[i]-1]:max_el;
        }
    }

    for(int i=0;i<answer.size();i++)
    {
        if(answer[i]<last_max)
            answer[i]=last_max;
    }

    return answer;
}
