import java.util.HashSet;
import java.util.Vector;
import java.util.Iterator;
import java.util.ArrayList;

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
        HashSet<Integer>[] list = new HashSet[32000+2];
        HashSet<Integer> set = new HashSet<>();
        set.add(N);
        list[1] = set;
        
        if(number==N)
            return 1;

        for(int i=2;i<=8;i++)
        {
            HashSet<Integer> set2 = new HashSet<>();
            for(int j=1;j<i;j++)
            {
                if(list[j]!=null)
                {
                    Iterator iter = list[j].iterator();
                    while(iter.hasNext())
                    {
                        int a = (int)iter.next();
                        if(list[i-j]!=null)
                        {
                            Iterator iter2 = list[i-j].iterator();
                            while(iter2.hasNext())
                            {
                                int b =(int)iter2.next();
                                int add = a+b;
                                int sub = a-b;
                                int mul = a*b;
                                int div = a/b;
                                if(add==number||sub==number||mul==number||div==number)
                                {
                                    return i;
                                }
                                if(add!=0) set2.add(add);
                                if(sub!=0) set2.add(sub);
                                if(mul!=0) set2.add(mul);
                                if(div!=0) set2.add(div);
                            }
                        }
                    }
                }
                    
            }
            set2.add(getN(N,i));
            list[i] = set2;
            System.out.println();
        }
        
        return -1;
    }
}
