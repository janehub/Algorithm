class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int[][] sum = new int[500][500];

        sum[0][0]=triangle[0][0];
        int colSum = sum[0][0];
        for(int i=1;i<triangle.length;i++)
        {
            colSum += triangle[i][0];
            sum[i][0]=colSum;
        }
        
        //i>=j
        //i,j = i-1,j-1 + i-1,j
        for(int i=1;i<triangle.length;i++)
        {
            for(int j=1;j<triangle[i].length;j++)
            {
                if(sum[i-1][j-1]>sum[i-1][j] || i<j)  //i>=j일 경우만 존재하기 때문
                    sum[i][j]=sum[i-1][j-1]+triangle[i][j];
                else
                {
                    sum[i][j]=sum[i-1][j]+triangle[i][j];
                }
            }
        }
        
        for(int i=0;i<triangle.length;i++)
        {
            //System.out.println(sum[triangle.length-1][i]);
            if(answer<sum[triangle.length-1][i])
                answer=sum[triangle.length-1][i];
        }
            
        
        return answer;
    }
}
