#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string,int> m;
    for(int i=0;i<phone_book.size();i++)
    {
        m[phone_book[i]]=1;
    }
    
    for(int i=0;i<phone_book.size();i++)
    {
        string s="";
        for(int j=0;j<phone_book[i].size();j++)
        {
            s+=phone_book[i][j];
            if(m[s]&&s!=phone_book[i])
            {
                return false;
            }
        }
    }
    
    return answer;
}
