import java.util.Vector;
import java.util.HashMap;

class Solution {
    int common=0;   //교집합 갯수   
    int sum=0;      //합집합 갯수     
    
    char toUpperCase(char c)
    {
        return (char)('A'+(c-'a'));
    }
    
    boolean isUpperCase(char c)
    {
        if(c>='A'&&c<='Z')
            return true;
        return false;
    }
    
    HashMap<String,Integer> parsing(String s)
    {
        Vector<Character> v1 = new Vector<>();
        HashMap<String,Integer> hm= new HashMap<>();    //다중집합
        
        for(int i=0;i<s.length();i++)
        {
            char c = s.charAt(i);
             if(c>='a'&&c<='z')  //소문자 -> 대문자
             {
                 v1.add(toUpperCase(c));
             }
             else
             {
                v1.add(c);
             }
        }
        
        for(int i=0;i<v1.size()-1;i++)
        {
            if(isUpperCase(v1.get(i))&&isUpperCase(v1.get(i+1)))
            {
                sum++;
                String sb = new StringBuilder().append(v1.get(i)).append(v1.get(i+1)).toString();

                if(hm.containsKey(sb))
                    hm.put(sb,hm.get(sb)+1);
                else
                    hm.put(sb,1);
            }

        }
        return hm;
    }
    
    public int solution(String str1, String str2) {
        int answer = 0;
        HashMap<String,Integer> m1=parsing(str1);
        HashMap<String,Integer> m2=parsing(str2);
        
        // System.out.println(m1);
        // System.out.println(m2);
        
        if(m1.size()==0&&m2.size()==0)
        {
            answer=1*65536;
        }
        else
        {
            for(String s: m1.keySet())
            {
                if(m2.containsKey(s))   //교집합
                {
                    common+=Math.min(m1.get(s),m2.get(s));
                }
            }

            sum-=common;

            answer=(int)(((double)common/sum)*65536);           
        }
        
        return answer;
    }
}
