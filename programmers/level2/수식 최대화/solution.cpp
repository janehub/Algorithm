#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    char prior[3]={'+','-','*'};
    string s= "";
    //parsing
    for(int i=0;i<expression.length();i++)
    {
         if(expression[i]<'0'||expression[i]>'9')
         {
            num.push_back(stoi(s));
            op.push_back(expression[i]);
             s="";
         }else
         {
             s+=expression[i];
         }
     }
     num.push_back(stoi(s));
    
    sort(prior,prior+3);
    do{
       vector<long long> c_num=num;
       vector<char> c_op=op;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<c_op.size();j++)
            {
                if(prior[i]==c_op[j])
                {
                    if(c_op[j]=='+'){
                        c_num[j]=c_num[j]+c_num[j+1];
                    }else if(c_op[j]=='-'){
                        c_num[j]=c_num[j]-c_num[j+1];
                    }else{
                        c_num[j]=c_num[j]*c_num[j+1];
                    }
                    c_num.erase(c_num.begin()+j+1);
                    c_op.erase(c_op.begin()+j);
                    j--;
                }
            }
        }
        
        answer= max(answer, abs(c_num[0]));
        
    }while(next_permutation(prior,prior+3));
    
    
    return answer;
}
