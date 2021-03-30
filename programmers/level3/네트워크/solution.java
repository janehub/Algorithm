import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        int[] chk = new int[200];
        Queue<Integer> q = new LinkedList<>();
        
        for(int j=0;j<n;j++)
        {
            if(chk[j]==1)
                continue;
            
            q.offer(j);
            chk[j]=1;
            while(!q.isEmpty())
            {
                int cur = q.poll();
                for(int i=0;i<n;i++)
                {
                    if(computers[cur][i]==1&&chk[i]==0)
                    {
                        q.offer(i);
                        chk[i]=1;
                    }

                }
            }
            answer++;
        }

        return answer;
    }
}
