import java.util.Stack;

class Solution
{
    public int solution(String s)
    {
        Stack<Character> stack = new Stack<>();
        int answer = 0;
        
        if(s.length()%2!=0)
           return 0;  

        for(int i=0;i<s.length();i++)
        {
            Character a = s.charAt(i);
            if(!stack.empty()&&stack.peek()==a)
            {
                stack.pop();
            }
            else
            {
                stack.push(a);
            }
        }
        
        if(!stack.empty())
        {
            Character b = stack.peek();
            stack.pop();
            while(!stack.empty())
            {
                if(stack.peek()==b)
                   stack.pop();
                else
                    return 0;
            }
        }
        
        return 1;
    }
}
