#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int x = arr1.size();
    int y = arr2[0].size();
    
    //cout<<x<<" "<<y;
    
    for(int i=0;i<x;i++)
    {
        vector<int> v;
        for(int j=0;j<y;j++)
        {
            
            //cout<<i<<""<<j<<" ";
            //arr1의 i행 *arr2의 j열
            int sum=0;
            for(int k=0;k<arr1[0].size();k++)
            {
                sum+=arr1[i][k]*arr2[k][j];
            }
            //cout<<sum<<" ";
            v.push_back(sum);
        }
        //cout<<endl;
        answer.push_back(v);
    }

    return answer;
}
