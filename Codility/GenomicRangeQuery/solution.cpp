/*
Detected time complexity:
O(N * M)
*/
#include <vector>
#include <unordered_map>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> v;
    unordered_map <char,int> m;
    m['A']=1; m['C']=2; m['G']=3; m['T']=4;

    for(int i=0;i<P.size();i++)
    {
        int min=9;
        for(int j=P[i];j<=Q[i];j++)
        {
            min=min>m[S[j]]?m[S[j]]:min;
        }

        v.push_back(min);
    }

    return v;
}
