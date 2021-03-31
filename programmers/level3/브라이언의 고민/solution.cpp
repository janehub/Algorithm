#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> word;
int start_idx[26]={0};  //a~z 소문자 시작위치 인덱스
int end_idx[26]={0};    //a~z 소문자 마지막위치 인덱스
int cnt[26]={0};    //a~z 소문자 나온 횟수 저장

bool isAlphabet(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        return true;
    else
        return false;
}

bool isUpperCase(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    else
        return false;
}

bool isLowerCase(char c)
{
    if(c>='a'&&c<='z')
        return true;
    else
        return false;
}

bool isRule1(char op,string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            if(!isUpperCase(s[i]))
                return false;
        }else{
            if(s[i]!=op)
                return false;
        }
    }
    return true;
}

bool chkRule1(vector<int> v,string s)
{
    int pr_ed;
    int next_st;
    for(int i=0;i<v.size();i++)
    {
        int op=v[i];
        int start=start_idx[op];
        int end = end_idx[op];
        if(start-1<0 || end+1>s.size()-1)
            return false;
        string subs = s.substr(start-1,end-start+3);
        if(!isRule1(op+'a',subs))
            return false;
        
        if(i==0)
        {
            pr_ed=end; 
        }
        else
        {
           next_st=start;
            if(next_st-pr_ed<=2)
                return false;
            pr_ed=end; 
        }
    }

    
    return true;
}

bool isFmtWord(string s)    //rule2안의 단어가 rule1 만족 또는 대문자로만 구성
{
    if(s.size()==0)
        return false;
    else if(!isUpperCase(s[0]))
        return false;
    else if(s.size()==1)
        return true;
    else if(isUpperCase(s[1]))
    {
        for(int i=2;i<s.size();i++)
            if(!isUpperCase(s[i]))
                return false;
    }
    else
    {
        char op = s[1];
        for(int i=2;i<s.size();i++)
        {
            if(i%2==0)
            {
                if(!isUpperCase(s[i]))
                    return false;
            }
            else
            {
                if(s[i]!=op)
                    return false;
            }
        }
    }
    return true;
}

bool isFmtWordR1(string s)  //단어가 rule1 또는 대문자, 또는 쪼개질 수 있음
{
    if(s.size()==0)
        return true;
    else if(!isUpperCase(s[0]))
        return false;
    else if(s.size()==1)
        return true;
    else            //rule1+대문자, 대문자+rule1, 대문자+rule1+대문자, rule1+대문자+rule1
    {
        for(int i=0;i<s.size();i++)
        {
            if(isLowerCase(s[i]))
            {
                int start = start_idx[s[i]-'a'];
                int end = end_idx[s[i]-'a'];
                if(!isRule1(s[i],s.substr(start-1,end-start+3)))
                    return false;
                i=end;
            }
        }
        
        return true;
    }
    
    return false; 
}

string getFmtWord(string s)
{
    string a="";
    if(s.size()<=1)
        return s;
    
    a=s[0];
    if(isUpperCase(s[1]))
    {
        for(int i=1;i<s.size();i++)
        {
            a+=s[i];
        }  
    }
    else
    {
        char op = s[1];
        for(int i=2;i<s.size();i+=2)
        {
            a+=s[i];
        }
    }
    
    return a;
}

vector<string> getFmtWordR1(string s,int st_idx,int ed_idx)
{   
    vector<string> a;
    if(s.size()<=1)
    {
        a.push_back(s);
        return a;
    }
    
    string tmp="";
    int op;
    int i=0;
    for(i=st_idx;i<ed_idx;i++)
    {
        if(isUpperCase(s[i]))
        {
            tmp+=s[i];
        }
        else
        {
            if(tmp.substr(0,tmp.size()-1).size()>0)
            {
                a.push_back(tmp.substr(0,tmp.size()-1));
            }
                
            op=s[i]-'a';
            int start=start_idx[op];
            int end = end_idx[op];
            tmp="";
            int j=0;
            for(j=start-1;j<=end+1;j=j+2)
            {
                tmp+=s[j];
            }
            a.push_back(tmp);
            i=end+1;
            tmp="";

        }
            
    }
    if(tmp.size()>0)
    {
        a.push_back(tmp);
    }
        
    
    return a;
}

bool cutWords(string s,vector<int> rul2_idx){
    int last_idx=0;
    
    if(rul2_idx.size()==0)
    {
        vector<string> fmt_word = getFmtWordR1(s,0,s.size());
        for(int k=0;k<fmt_word.size();k++)
        {
           word.push_back(fmt_word[k]); 
        }
            
    }
    else
    {
        last_idx=rul2_idx[0];
        if(last_idx>0)
        {
            vector<string> fmt_word = getFmtWordR1(s,0,rul2_idx[0]);
            for(int k=0;k<fmt_word.size();k++)
                word.push_back(fmt_word[k]);
        }


        for(int i=1;i<rul2_idx.size();i++)
        {
            if(rul2_idx[i]<last_idx)
            {
                continue;
            }
            
            if(rul2_idx[i]-last_idx-1>0)
            {
                string f = s.substr(last_idx+1,rul2_idx[i]-last_idx-1);
                if(s[last_idx]==s[rul2_idx[i]])
                {
                    if(isFmtWord(f))
                    {
                        string fmt_word = getFmtWord(f);
                        word.push_back(fmt_word);
                    }
                    else
                    {
                        return false;
                    }                    
                }
                else
                {
                    vector<string> fmt_word = getFmtWordR1(s,last_idx+1,rul2_idx[i]);
                    for(int k=0;k<fmt_word.size();k++)
                    {
                        word.push_back(fmt_word[k]);
                    }
                        
                }     
            }
            last_idx=rul2_idx[i];           
        }

        if(last_idx+1<s.size())
        {
            vector<string> fmt_word = getFmtWordR1(s,last_idx+1,s.size());
            for(int k=0;k<fmt_word.size();k++)
                word.push_back(fmt_word[k]);
        }    
    }
    
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    word.clear();
    int N=sentence.size();
    vector<int> v;    //기호(알파벳 소문자 0~25) 순서대로 저장
    vector<int> rul2_idx;   //rule2를 만족하는 인덱스값 저장
    vector<int> rul1_idx;   //rule1을 만족하는 인덱스값 저장
    
    for(int i=0;i<26;i++)
    {
        start_idx[i]=0;
        end_idx[i]=0;
        cnt[i]=0;
    }

    for(int i=0;i<N;i++)
    {
        if(!isAlphabet(sentence[i]))
            return "invalid";
        
        if(isLowerCase(sentence[i]))
        {
           int c=sentence[i]-'a';
            cnt[c]++;
            end_idx[c]=i;
            if(find(v.begin(),v.end(),c)==v.end())
            {
                v.push_back(c);
                start_idx[c]=i;
            }
              
        }

    }
    
    if(v.size()==0)
        return sentence;
     
    for(int i=0;i<v.size();i++)
    {
        if(cnt[v[i]]==2) // bAb -> A, AbAbA -> A A A, 2개일 경우 규칙2로 설정
        {
            
            if(end_idx[v[i]]-start_idx[v[i]]<=1)    //aa 불가능
            {
                return "invalid";
            } 
            rul2_idx.push_back(start_idx[v[i]]);
            rul2_idx.push_back(end_idx[v[i]]);
        }
        else
        {
            rul1_idx.push_back(v[i]);
        }
    }
    
    bool flag=false;
    if(rul1_idx.size()>0)
    {
        flag=chkRule1(rul1_idx,sentence);    // rule1 만족하는지 확인
        if(!flag)
            return "invalid";
    }
    
    flag=cutWords(sentence,rul2_idx);
    if(!flag)
        return "invalid";
        
    for(int i=0;i<word.size();i++)
    {
        answer+=word[i]+" ";
    }
    
    answer=answer.substr(0,answer.size()-1);
    
    return answer;
}
