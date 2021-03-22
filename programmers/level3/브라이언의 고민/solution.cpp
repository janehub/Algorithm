#include <string>
#include <set>
#include <iostream>

using namespace std;

bool isUppercase(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    else
        return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    set<char> set;
    string answer = "";
    string s1="";
    string s2="";
    int length = sentence.size();
    if(length<=2)
        return sentence;
    
    char first = sentence[0];
    set.insert(first);
    bool found=false;
    bool hasLower=false; //소문자 들어있는지 체크
    if(!isUppercase(first))   //첫글자가 소문자 -> 규칙2
    {
        for(int j=1;j<length;j++)
        {
            if(sentence[j]==first)
            {
                found=true;
                s1=sentence.substr(1,j-1);
                s2=sentence.substr(j+1);
                break;
            }
            if(!isUppercase(sentence[j])&&!found)
                hasLower=true;
        }
        
        if(!found)
            return "invalid";
        
        if(s1.size()==0)
            return "invalid";

        string s11="";
        if(hasLower)    //규칙1 만족하는지 확인
        {
            int lower=s1[1];
            set.insert(lower);
            s11+=s1[0];
            s11+=s1[2];
            for(int i=3;i<s1.size();i+=2)
            {
                if(s1[i]!=lower)
                    return "invalid";
                s11+=s1[i+1];
            }
            s1=s11;
        }
    }
    else{
        char second = sentence[1];
        s1+=sentence[0];
        int j=1;
        if(!isUppercase(second))    //규칙1만족하는지 확인
        {
            if(set.find(second)!=set.end())
                return "invalid";
            else
                set.insert(second);
            for(j=1;j<length;j++)
            {
                if(j%2==0)
                {
                    if(!isUppercase(sentence[j]))
                        return "invalid";
                    s1+=sentence[j];
                }
                else
                {
                    if(sentence[j]!=second)
                        break;
                }
            }
        }
        else
        {
            for(j=1;j<length;j++)
                if(!isUppercase(sentence[j]))
                    break;
            s1=sentence.substr(0,j);
        }
        s2=sentence.substr(j);

    }
    
    // cout<<"s1 :"<<s1<<endl;
    // cout<<"s2 :"<<s2<<endl;
    
    string s22="";
    first = s2[0];
    length= s2.length();
    found=false;
    hasLower=false; //소문자 들어있는지 체크
    if(!isUppercase(first))   //첫글자가 소문자 -> 규칙2
    {
        if(set.find(first)!=set.end())
            return "invalid";
        else
            set.insert(first);
        if(s2[length-1]!=first)
            return "invalid";
        for(int j=1;j<length-1;j++)
        {
            if(!isUppercase(s2[j]))
            {
                hasLower=true;
            }
            s22+=s2[j];
        }
        s2=s22;
    }
    if(isUppercase(first)||hasLower)
    {
        s22="";
        char second = s2[1];
        s22+=s2[0];
        int j=1;
        if(!isUppercase(second))    //규칙1만족하는지 확인
        {
            if(set.find(second)!=set.end())
                return "invalid";
            else
                set.insert(second);
            for(j=1;j<length;j++)
            {
                if(j%2==0)
                {
                    s22+=s2[j];
                }
                else
                {
                    if(s2[j]!=second)
                        break;
                }
            }
            s2=s22;
        }
        else
        {
            for(j=1;j<length;j++)
                if(!isUppercase(s2[j]))
                    break;
        }
        
    }
    
    if(s1.size()==0 || s2.size()==0)
    {
        string tmp = s1+s2;
        answer = tmp.substr(0,1)+" "+tmp.substr(1);
    }
    else{
        answer = s1+" "+s2;
    }
    return answer;
}
