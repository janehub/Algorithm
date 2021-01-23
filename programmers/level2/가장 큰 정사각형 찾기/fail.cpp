#include <iostream>
#include<vector>
using namespace std;

int max_size(int i,int j, vector<vector<int>> &board)
{
    int distance;
    int max_len=min(board.size()-i,board[0].size()-j);  //최대로 갈 수 있는 길이
    // cout<<"i: "<<i<<endl;
    // cout<<"j: "<<j<<endl;
    // cout<<"max_len: "<<max_len<<endl;
    
    //현재 위치로부터 오른쪽, 아래로 탐색 _|모양
    for(distance=1;distance<max_len;distance++)
    {
      //   cout<<"distance: "<<distance<<endl;
        for(int k=0;k<=distance;k++)
        {
            //cout<<board[i+distance][j+k];
            //cout<<board[i+k][j+distance];
            if(board[i+distance][j+k]!=1||board[i+distance][j+k]!=1)
            {
                return (distance-1+1)*(distance-1+1);
            }
        }
      //  cout<<endl;
    }
    
    distance--;

    return (distance+1)*(distance+1);
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]==1){
                //cout<<max_size(i,j,board)<<endl;
                answer=max(answer,max_size(i,j,board));
                int tmp=min(board.size()-i+1, board[0].size());
                if(answer>=tmp*tmp)
                {
                    return answer;
                }
            }
                
        }
        
    }

    return answer;
}
