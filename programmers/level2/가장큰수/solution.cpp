#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int digit=8;

bool compare(int a,int b){
    string c = to_string(a);
    string d = to_string(b);
    string cc=c+d;
    string dd=d+c;
 
    cc.insert(cc.length(),digit-cc.length(),'0');
    int x = stoi(cc);
    dd.insert(dd.length(),digit-dd.length(),'0');
    int y = stoi(dd);
    
    if(x==y)
    {
        return a<b?true:false;
    }
    else if(x>y)
    {
        return true;
    }
    else
    {
        return false;   
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    bool isZero=true;
    
    for(int n:numbers)
    {
       if(n!=0)
           isZero=false;
    }
    
    if(isZero)
        return "0";
    
    sort(numbers.begin(),numbers.end(),compare);
    
    for(int n:numbers)
    {
        answer+=to_string(n);
    }
    
    return answer;
}
