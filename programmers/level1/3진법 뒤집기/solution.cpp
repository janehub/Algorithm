#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    int i=n;
    do
    {
        v.push_back(i%3);
        i=i/3;
        
    }while(i>2);
    
    if(i>0)
       v.push_back(i);
    
    for(int i=0;i<v.size();i++)
    {
        answer+=v[i]*pow(3,v.size()-1-i);
    }
        
    
    return answer;
}
