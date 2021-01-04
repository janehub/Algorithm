#include <string>
#include <vector>

using namespace std;

string u_job(string u){
    string s;
    for(int i=1;i<=u.length()-2;i++){
        if(u[i]=='(')
            s+= ')';
        else
            s+='(';
    }
    
    return s;
}

string right_string(string p){
    int cnt=0; /* '(':+1, ')':-1 */
    bool right=true; //올바른 문자열인지 여부
    string u;
    string v;
    
    if(p=="")
        return "";
    
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='(')
        {
            cnt++;
        }else if(p[i]==')')
        {
            cnt--;
        }
        
        if(cnt<0)
        {
            right=false;
        }
        
        if(cnt==0)
        {
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }
    
    //u가 올바른 문자열인지 판단
    if(right)
    {
        return u+right_string(v);
    }else{
        return "("+ right_string(v)+")" + u_job(u);
    }
}

string solution(string p) {
    string answer = "";
    
    answer = right_string(p);
    
    return answer;
}
