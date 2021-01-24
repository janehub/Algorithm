#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int chk[1001][1001];
    
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++)
            chk[i+1][j+1]=board[i][j];
    
     for(int i=1;i<=board.size();i++)
     {
         for(int j=1;j<=board[0].size();j++)
         {
             if(chk[i][j]==1)
             {
                 chk[i][j]= min(min(chk[i-1][j-1], chk[i-1][j]), chk[i][j-1])+1;
                 answer=max(answer,chk[i][j]);
             }  
         }
     }
    
            
    return answer*answer;
}
