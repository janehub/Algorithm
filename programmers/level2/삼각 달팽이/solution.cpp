#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> num[1001];
    int total=1;
    int k=0;//방향:아래,오른쪽,위
    int row=1;
    int left=0;
    int right=0;
    for(int b=n;b>=1;b--)
    {
       // printf("b: %d\n",b);
        if(k%3==0)
        {
          //  printf("k=0\n");
             for(int i=0;i<b;i++)
             {
                // printf("%d / %d / %d / %d\n",row, total, left, right);
                 num[row].insert(num[row].begin()+left,total);
                 row++;
                 total++;
             }
             left++;
             row--;
        }else if(k%3==1)
        {
            //printf("k=1\n");
            int lpp=left;
            for(int i=0;i<b;i++)
            {
                //printf("%d / %d / %d / %d\n",row, total, left, right);
                num[row].insert(num[row].begin()+lpp,total);
                lpp++;
                total++;
            }
        }else if(k%3==2)
        {
           // printf("k=2\n");
            for(int i=0;i<b;i++)
            {
                row--;
               // printf("%d / %d / %d / %d\n",row, total, left, right);
                num[row].insert(num[row].end()-right,total);
                total++;
            }
            right++;
            row++;
        }
        k++;
    }
    
    for(int i=1;i<=n;i++)
    {
        answer.insert(answer.end(),num[i].begin(),num[i].end());
    }
    
    return answer;
}
