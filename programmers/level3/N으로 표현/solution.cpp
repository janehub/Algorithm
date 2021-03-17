import java.util.HashSet;
import java.util.Vector;
import java.util.Iterator;

class Solution {
    
    int getN(int N, int len)
    {
        int num=0;
        for(int i=0;i<len;i++)
        {
            num+=N*Math.pow(10,i);
        }
        
        return num;
    }
    
    public int solution(int N, int number) {
        int answer = 0;
        HashSet<Integer> set = new HashSet<>();
        
        set.add(N);
        for(int i=2;i<=8;i++)
        {
            Iterator iter = set.iterator();
            Vector<Integer> v = new Vector<>();
            int add=0;int sub=0;int mul=0;int div=0;
            
            while(iter.hasNext())
            {
                int a = (int)iter.next();
                add = a+N;
                sub = a-N;
                mul = a*N;
                div = a/N;
                if(add==number||sub==number||mul==number||div==number)
                {
                    return i;
                }
                v.add(add);
                v.add(sub);
                v.add(mul);
                v.add(div);
            }
            for(int k=0;k<v.size();k++)
            {
               //사칙연산
                set.add(v.get(k));
            }
            
            //자릿수증가
            set.add(getN(N,i));
        }
        
        return -1;
    }
}
