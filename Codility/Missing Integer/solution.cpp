int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int arr[1000001]={0};

    for(int a:A)
        if(a>0)
            arr[a]++;

    for(int i=1;i<=1000001;i++)
        if(arr[i]==0)
            return i;
    
    return 1000001;
}
