/*
Detected time complexity:
O(N + M)
*/
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> v;
    int A[100002]={0};
    int C[100002]={0};
    int G[100002]={0};
    int T[100002]={0};

    for(int i=0;i<S.size();i++)
    {
        A[i+1]=A[i];
        C[i+1]=C[i];
        G[i+1]=G[i];
        T[i+1]=T[i];
        
        switch (S[i])
        {
            case 'A':
                A[i+1]=A[i]+1;
                break;
            case 'C':
                C[i+1]=C[i]+1;
                break;
            case 'G':
                G[i+1]=G[i]+1;
                break;
            case 'T':
                T[i+1]=T[i]+1;
            
        }
    }
    
    for(int i=0;i<P.size();i++)
    {
        if(A[Q[i]+1]-A[P[i]]>0)
            v.push_back(1);
        else if(C[Q[i]+1]-C[P[i]]>0)
            v.push_back(2);
        else if(G[Q[i]+1]-G[P[i]]>0)
            v.push_back(3);
        else
            v.push_back(4);
    }
    
    return v;
}
