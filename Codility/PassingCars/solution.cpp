/*
Detected time complexity:
O(N)
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum=0;  //east방향 차 누적하여 count
    long long answer=0;

    for(int a:A)
        if(a==0)
            sum++;
        else if(a==1)
        {
            answer+=sum;
            if(answer>1000000000)
                return -1;
        }


    return answer;
}
