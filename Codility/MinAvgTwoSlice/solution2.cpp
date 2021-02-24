/*
원소가 4개(a, b, c, d)인 그룹은 (a, b)와 (c, d)를 나누었을 때, 각각의 평균의 작은 값 이상이 된다.
참고:
https://cheolhojung.github.io/posts/algorithm/Codility-MinAvgTwoSlice.html


Detected time complexity:
O(N)
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    double min=(A[0]+A[1])/(double)2;
    int answer=0;

    for(int i=2;i<A.size();i++)
    {
        double avg = (A[i-2]+A[i-1]+A[i])/(double)3;
        if(min>avg)
        {
            min=avg;
            answer=i-2;
        }

        avg = (A[i-1]+A[i])/(double)2;
                if(min>avg)
        {
            min=avg;
            answer=i-1;
        }
    }

    return answer;

}
