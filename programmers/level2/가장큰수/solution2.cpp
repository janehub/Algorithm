#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a,int &b){
    string x = to_string(a);
    string y = to_string(b);

    if(x+y>y+x)
        return true;
    else
        return false;   
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),compare);
    
    for(int n:numbers)
    {
        answer+=to_string(n);
    }
    
    if(answer[0]=='0')
        return "0";
    
    return answer;
}
