/*
실패, 0:배경체크 제거
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct Poinfo{
    int x;
    int y;
    int color;
    int g_id;
} Poinfo;

bool operator==(const Poinfo& a, const Poinfo& b)
{
    if(a.x<0||b.x<0||a.y<0||b.y<0)
        return false;
    return (a.x==b.x)&&(a.y==b.y)&&(a.color==b.color);
}

vector<Poinfo> group;

//기존 그룹안 좌표와 닿는지 체크
//있으면 기존 그룹에 추가, 없으면 새로운 그룹으로 등록
int inGroup(Poinfo p)
{
    Poinfo up = {p.x-1,p.y,p.color};
    Poinfo left = {p.x,p.y-1,p.color};
    
    for(int i=0;i<group.size();i++)
    {
        if(up==group[i]||left==group[i])
        {
            return group[i].g_id;
        }
    }
    return -1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int id=0;   //그룹 번호매기기
    vector<int> p_size;

    group.clear();
    p_size.clear();
    
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
         {
             Poinfo p={i,j,picture[i][j]};
             int f_id = inGroup(p);
             
             if(picture[i][j]!=0)
             {
                 if(f_id<0)
                 {
                     Poinfo p={i,j,picture[i][j], id};
                     group.push_back(p);
                     p_size.push_back(1);
                     number_of_area++; 
                     id++;
                 }
                 else
                 {            
                     Poinfo p={i,j,picture[i][j],f_id};
                     group.push_back(p);
                     p_size[f_id]++;
                 }
            }
         }
    }
    
    max_size_of_one_area = *max_element(p_size.begin(),p_size.end());
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
