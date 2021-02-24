/*
Detected time complexity: O(N ** 2)
*/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer=0;
    double min=0;
    double sum=0;
    bool isFirst=true;

    for(int i=0;i<A.size()-1;i++)
    {
        sum=A[i];
        for(int j=i+1;j<A.size();j++)
        {
            sum+=A[j];
            if(isFirst)
            {
                min=sum/2;
                answer=0;
                isFirst=false;
            }else
            {
                if(min>sum/(double)(j-i+1))
                {
                    min=sum/(double)(j-i+1);
                    answer=i;
                }
            }
        }
    }

    return answer;
}
