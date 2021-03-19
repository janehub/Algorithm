#include <iostream>
#include <queue>
using namespace std;

const int INF = 9999;
int x[4] = {-1,0,1,0};
int y[4] = {0,-1,0,1};
int chk[10][10]={0};

struct point{
	 int x;
	 int y;
};

int getMinsDistance(int start, int n, int arr[][10])
{
	int min_dis=INF;
	queue<pair<point,int>> q;
	
	point p1={0,0};
	q.push(make_pair(p1,1));
	chk[0][0]=1;
	while(!q.empty())
	{
		 int cur_x = q.front().first.x;
		int cur_y = q.front().first.y;
		int cur_dis=q.front().second;
		q.pop();
		
		if(cur_x==n-1 &&cur_y==n-1)
		{
				min_dis = min(cur_dis,min_dis);
				break;
		}		
		
		for(int i=0;i<4;i++)
		{
			int next_x=cur_x+x[i];
			int next_y=cur_y+y[i];
			
			if(next_x>=0&&next_x<n&&next_y>=0&&next_y<n)
			{
				if(arr[next_x][next_y]!=0 && chk[next_x][next_y]==0)
				{
					point p2={next_x,next_y};
					q.push(make_pair(p2,cur_dis+1));
					chk[next_x][next_y]=1;
				}
				
			}
		}
		
	}
	
	return min_dis;
	
}

int main() {
	int answer=0;
	int arr[10][10]={0};
	int N=0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	if(arr[0][0]==0)
		return 0;
	
	answer = getMinsDistance(0, N, arr);
	if(answer==9999)
		return 0;
	cout<<answer;
	
	return 0;
}
