/*
남은 자릿수 앞까지의 수 중에서 최댓값을 구하여 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> v;
    int cnt=0;
    const int num=number.length()-k;  /* k개의 수를 빼고 남은 최종 자릿수 */
    int digit=0;  /*구하려는 남은 자릿수*/
    for(char c:number){
        v.push_back(c-'0');
    }
    
    int start = 0;
    int end;
    digit=num;
    while(cnt<num)
    {
        end = number.length()-digit;
        int max=v[start];
        for(int i=start;i<=end;i++)
        {
            if(max<v[i]){
                max=v[i];
                start=i;
            }
                
        }
        answer+=max+'0';
        start++;
        digit--;
        cnt++;
    } 
    
    return answer;
}
