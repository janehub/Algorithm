#include <string>
#include <vector>

using namespace std;
int zero;
int one;

void cpr(vector<vector<int>> arr)
{
    int len = arr.size();
    //printf("%d\n", len);
    
    if(arr.size()==1){
        return;
    }
        
    int a = arr[0][0];
    //모두 같은 수 인지 체크
    bool same=true;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
             if(arr[i][j]!=a)
             {
                same=false;
                break;
             }               
        }
        if(!same)
        {
            break;
        }
    }

    if(same)
    {
        //printf("모두 같음\n");
        if(a==0)
        {
            zero=zero-len*len+1;
        }else
        {
            one=one-len*len+1; 
        }
        return;        
    }
    
    //영역 나누기
    vector<vector<int>> v(len/2, vector<int>(len/2,0));
    for(int i=0;i<len/2;i++)
        for(int j=0;j<len/2;j++)
            v[i][j]=arr[i][j];
    cpr(v);
    
    for(int i=0;i<len/2;i++)
    for(int j=len/2;j<len;j++)
        v[i][j-len/2]=arr[i][j];
    cpr(v);
    
    for(int i=len/2;i<len;i++)
    for(int j=0;j<len/2;j++)
        v[i-len/2][j]=arr[i][j];
    cpr(v);
    
    for(int i=len/2;i<len;i++)
    for(int j=len/2;j<len;j++)
        v[i-len/2][j-len/2]=arr[i][j];
    cpr(v);

}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    zero=0;
    one=0;
    
    //초기 갯수세기
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j]==0)
                zero++;
            else
                one++;
        }
    }
    //printf("초기 : %d %d\n",zero,one);
    
    cpr(arr);
    
     //printf("결과 : %d %d\n",zero,one);
    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}
