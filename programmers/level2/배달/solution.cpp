/*
그래프 최단거리
Dijkstra Algorithm
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

vector<pair<int,int>> v[50+1];
int dis[51]; //1에서 최종목적지까지의 걸린시간

int dijkstra(int start)
{
    dis[start]=0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    
    while(!q.empty())
    {
        int cur = q.top().first;
        int cur_dis = - q.top().second;   //priority queue 오름차순화
        q.pop();
        if(cur_dis>dis[cur])
                continue;
        
        for(int i=0;i<v[cur].size();i++)
        {
            //cout<<v[store][i].first<<" : "<<v[store][i].second<<endl;
            //현재노드의 인접노드
            int next = v[cur][i].first;
            //현재노드의 인접노드로 거쳐가는 비용
            int next_dis = cur_dis + v[cur][i].second;
            
            if(next_dis<dis[next])
            {
                dis[next] = next_dis;
                q.push(make_pair(next, -next_dis));
            }
        }
    }
    
    
    return 0;
}

int solution(int N, vector<vector<int> > road, int K) {  
    int answer = 0;
    //초기화
    for(int i=0;i<51;i++)
    {
        v[i].clear();
        dis[i]=INF;
    }

    for(int i=0;i<road.size();i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    
    answer = dijkstra(1);
    
    for(int i=1;i<N+1;i++)
        if(dis[i]<=K)
            answer++;

    return answer;
}
