#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt=0;
    char arr[31][31];
    int chk[31][31]={0};
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=board[i][j];

    //초기값 출력
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout<<arr[i][j];
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    
    do
    {
        fill(&chk[0][0],&chk[30][31],0);
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(  arr[i-1][j-1]==arr[i][j]
                  && arr[i-1][j]==arr[i][j]
                  && arr[i][j-1]==arr[i][j]
                  && arr[i][j]!='-')
                {
                    chk[i-1][j-1]=chk[i-1][j]=chk[i][j-1]=chk[i][j]=1;
                }
            }
        }   

        cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(chk[i][j]==1)
                    cnt++;
        //cout<<cnt<<endl;
        answer+=cnt;
        for(int j=0;j<n;j++)
        {
            int t=m-1;
            for(int i=m-1;i>=0;i--)
            {
                if(chk[i][j]==0)
                {
                    arr[t][j]=arr[i][j];
                    t--;
                }
            }

            for(int k=t;k>=0;k--)
            {
                arr[k][j]='-';
            }
        }
        
    }while(cnt!=0);
    
    
    
        //초기값 출력
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout<<arr[i][j];
    //     cout<<endl;
    // }
    
    return answer;
}
