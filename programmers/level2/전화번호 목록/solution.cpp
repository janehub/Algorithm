#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if(a.length()<b.length())
    {
        return true;
    }else if(a.length()>b.length())
    {
        return false;   
    }
    else
    {
        return a<=b?true:false;
    }
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end(),compare);
   
    for(int k=0;k<phone_book.size()-1;k++)
    {
        string first=phone_book[k];
        for(int j=k+1;j<phone_book.size();j++)
        {
            bool chk=true; //접두어 같은지 체크

            for(int i=0;i<first.length();i++){
               if(first[i]!=phone_book[j][i])
               {
                   chk = false;
               }
            }

            if(chk)
            {
                return false;
            }
        }
    }
    
    
    return answer;
}
