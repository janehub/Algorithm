#include <unordered_map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int,int> m;
    int sum=X*(X+1)/2;
    int cnt=0;

    for(int i=0;i<A.size();i++)
    {
        if(m[A[i]]==0)
        {
            cnt+=A[i];
            m[A[i]]++;
        }
        if(cnt==sum)
            return i;
    }

    return -1;
}
