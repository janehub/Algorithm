/* BFS*/

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visit[100][100];

int bfs(int i,int j,int m, int n, vector<vector<int>> picture)
{
    int size = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visit[i][j]=true;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //4방향 탐색
        for(int k=0;k<4;k++)
        {
            int mx = x + dx[k];
            int my = y + dy[k];
            
            if(mx>=0&&my>=0&&mx<m&&my<n)
            {
                if(picture[i][j]==picture[mx][my]&&visit[mx][my]==false)
                {
                    visit[mx][my]=true;
                    q.push(make_pair(mx,my));
                    size++;
                }
            }
        }
        
    }
    
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    //방문여부 초기화
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            visit[i][j]=false;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(picture[i][j]!=0&&visit[i][j]==false)
            {
                int size = bfs(i,j,m,n,picture);
                max_size_of_one_area=max(size,max_size_of_one_area);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
