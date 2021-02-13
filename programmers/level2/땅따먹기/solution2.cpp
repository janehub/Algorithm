#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    if(land.size()==1)
        return *max_element(land[0].begin(),land[0].end());

    for(int i=1;i<land.size();i++)
    {
        for(int j=0;j<land[i].size();j++)
        {
            //직전 행 제외한 최댓값 구하기
            int max=0;
            for(int k=0;k<4;k++)
            {
                if(k!=j)
                {
                    max=max>land[i-1][k]?max:land[i-1][k];
                }
            }
            land[i][j]+=max;
            //cout<<land[i][j]<<endl;
        }
    }

    return *max_element(land.back().begin(),land.back().end());
}
