/*
제곱근
*/
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool selected[7];
bool chk[10000000];
vector<int> v;
int answer;

void isSosu()
{
	string a="";
	for(int el:v)
		a+=el;
	
	int num=stoi(a);
	
	if(num==0||num==1)  //소수아님
		return;
	
	if(chk[num])    //이미체크한 경우 넘어감
	{
		return;
	}
	else if(num==2){    //2는 소수
		chk[num]=true;
		answer++;
        return;
	}else{
		for(int i=2;i*i<=num;i++) //N의 약수는 무조건 sqrt(N)의 범위에 존재
		{
			if(num%i==0)    //소수아님
				return;
		}
	}
	
	chk[num]=true;
	answer++;
	return;
}

void permutation(int cnt,int digit, string s)
{
	if(cnt==digit)
	{
		isSosu();
		return;
	}
	
	for(int i=0;i<s.length();i++)
	{
		if(selected[i])
			continue;
			
		selected[i]=true;
		v.push_back(s[i]);
		permutation(cnt+1,digit,s);
		v.pop_back();
		selected[i]=false;
	}
}

int solution(string numbers) {
    answer = 0;
    fill_n(selected,10,false);
	fill_n(chk,10000000,false);

	for(int i=0;i<numbers.length();i++)
	{
		permutation(0,i+1,numbers);
	}

    return answer;
}
