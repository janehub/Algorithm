import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        Queue<Integer> q = new LinkedList();
        int[] dist = new int[n+1];  //거리
        boolean[] visit = new boolean[n+1]; //방문여부
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<n+1;i++){
            list.add(new ArrayList<Integer>());
        }
        
        for(int i=0;i<edge.length;i++){
            int a = edge[i][0];
            int b = edge[i][1];
            list.get(a).add(b);
            list.get(b).add(a);
        }
        
        q.add(1);
        visit[1]= true;
        while(!q.isEmpty())
        {
            int cur = q.poll();
            for(int i=0;i<list.get(cur).size();i++)
            {
                int next = list.get(cur).get(i);
                if(!visit[next])
                {
                    q.add(next);
                    visit[next]=true;
                    dist[next]=dist[cur]+1;
                }
            }
            
        }
        
        int max = 0;
        for(int i=2;i<dist.length;i++)
        {
            if(dist[i]>max)
            {
                max = dist[i];
                answer=1;
            }
            else if(dist[i]==max){
                answer++;
            }
            
        }
        
        return answer;
    }
}
