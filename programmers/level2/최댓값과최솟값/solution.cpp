#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int n;
    int min;
    int max;
    
    istringstream iss(s);
    iss>>n;
    min=max=n;
    while(iss>>n)
    {
   //     cout<<n<<endl;
        max=max>n?max:n;
        min=min<n?min:n;
    }
    
   // cout<<min<<" "<<max;
    answer=to_string(min)+" "+to_string(max);
    return answer;
}
