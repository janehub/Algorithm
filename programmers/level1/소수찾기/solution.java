class Solution {
    
    boolean isSosu(int n){
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)  //소수아님
               return false; 
        }
        return true;
    }
    
    public int solution(int n) {
        int answer = 0;
        
        for(int i=2;i<=n;i++)
        {
            if(isSosu(i))
                answer++;
        }
        return answer;
    }
}
