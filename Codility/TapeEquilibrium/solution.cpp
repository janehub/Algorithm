int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    //sum all of A
    int answer=-1;
    int sum=0;
    for(int a:A)
        sum+=a;

    //P 나누기 = sum에서 빼기
    int left = 0;
    
    for(int i=0;i<A.size()-1;i++)
    {
        left+=A[i];
        int right=sum-left;
        int diff= abs(left-right);
        if(answer==-1)
        {
            answer=diff;
        }else{
            answer=min(answer,diff);
        }
    }

    return answer;
}
