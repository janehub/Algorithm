int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum=(A.size()+1)*(A.size()+2)/2;
    for(int a:A)
        sum-=a;

    return sum;
}
