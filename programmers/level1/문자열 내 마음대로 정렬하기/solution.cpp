#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_n=0;

bool compare(string a, string b)
{
    if(a[g_n]==b[g_n])
    {
        return a<b;
    }
    else
    {
        return a[g_n]<b[g_n];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    g_n=n;
    
    sort(strings.begin(),strings.end(),compare);
    
    answer=strings;
    
    return answer;
}
