#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    
    do
    {
        v.push_back(n%10);
        n = n/10;
    }while(n>0);
    
    sort(v.begin(),v.end(),less<int>());
    
    for(int i=0;i<v.size();i++)
    {
        answer+=v[i]*pow(10,i);
    }
        
    return answer;
}
