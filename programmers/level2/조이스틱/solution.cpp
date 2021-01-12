#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int start =999; //A의 첫번째 위치
    int end=999; //A의 마지막 위치
    int len_a=0; //A의 길이
   
    //상하조작
    for(int i=0;i<name.size();i++)
        answer+=min(abs(name[i]-'A'),abs('Z'+1-name[i])); 
    printf("answer: %d\n",answer);
    //A의 시작, 끝위치 구하기
    for(int i=0;i<name.size();i++)
    {
        int temp_len=0;
        int s=i;
        int e=s;
        if(name[i]=='A')
        {
            temp_len++;
            for(int j=s+1;j<name.size();j++)
            {
                temp_len++;
                if(name[j]!='A')
                {
                    e=j;
                    break;
                }
            }
        }
        if(temp_len>len_a)
        {
            len_a=temp_len;
            start=s;
            end=e;
        }
    }
    
    //전부A일 경우 0리턴
    if(start==0&&end==0)
        return 0;
    
    printf("%d %d\n",start,end);
    
    if(start!=999&&(len_a>start||len_a>name.size()-end))  //A가 있을 경우, 가장 긴 A가 좌우 길이보다 클 경우
    {
        printf("남은길이 %d %d\n",name.size()-end-1,start-1);
        if(name.size()-end-1<start-1||start==1) //좌측으로 우선이동
        {
            printf("left이동\n");
            //좌측
            answer+=name.size()-end;
            //우측으로 돌아가기
            if(start>1)
                 answer+=name.size()-end;
            //남은 우측
            answer+=start-1;
        }else //우측으로 우선이동
        {
             printf("right이동\n");
            //우측
            answer+=start-1;
            //좌측으로 돌아가기
            if(end>start)
                answer+=start-1;
            //남은 좌측
            answer+=name.size()-end;
        }
    }else
    {
        answer+=name.size()-1;
    }
    return answer;
}
