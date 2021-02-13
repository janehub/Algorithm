#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void bfs(vector<vector<int> > &land, int row, int col,int sum)
{
    sum+=land[row][col];
   // cout<<row<<" "<<col<<" "<<land[row][col]<<endl;
    
    if(row==land.size()-1)
    {
     //   cout<<row<<" "<<sum<<endl;
        answer=max(answer,sum);
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        if(i!=col)
        {
           bfs(land,row+1,i,sum); 
        } 
    }
}

int solution(vector<vector<int> > land)
{
    answer = 0;

    for(int i=0;i<4;i++)
    {
        bfs(land,0,i,0);
    }
        

    return answer;
}
