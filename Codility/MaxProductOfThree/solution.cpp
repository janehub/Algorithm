/*
Detected time complexity:
O(N * log(N))
*/
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long long max=0;
    int n=A.size();

    sort(A.begin(),A.end());

    max=A[0]*A[1]*A[2];

    if(A[0]*A[1]*A[n-1]>max)
        max=A[0]*A[1]*A[n-1];
    if(A[0]*A[n-2]*A[n-1]>max)
        max=A[0]*A[n-2]*A[n-1];
    if(A[n-3]*A[n-2]*A[n-1]>max)
        max=A[n-3]*A[n-2]*A[n-1];

    return max;
}
