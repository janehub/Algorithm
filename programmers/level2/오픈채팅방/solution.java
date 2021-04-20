import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    
    class Log{
        int action; //0:Enter, 1:Leave
        String id;
        public Log(int action,String id)
        {
            this.action = action;
            this.id = id;
        }
    }
    
    public String[] solution(String[] record) {
        String[] answer;
        Map<String, String> m = new HashMap<>();   //id nickname match
        //Log[] log = new Log[record.length];
        ArrayList<Log> log = new ArrayList<>();
        
        for(int i=0;i<record.length;i++)
        {
            String[] sArr = record[i].split("\\s");
            if(sArr[0].equals("Enter"))
            {
                m.put(sArr[1],sArr[2]);
                //log[i]=new Log(0,sArr[1]);
                log.add(new Log(0,sArr[1]));
            }else if(sArr[0].equals("Leave")){
                //log[i]=new Log(1,sArr[1]);
                log.add(new Log(1,sArr[1]));
            }else{  //Change
                m.put(sArr[1],sArr[2]);
            }
        }
        
        int k=0;
        answer = new String[log.size()];
        for(Log l:log)
        {
            String nickname = m.get(l.id);
            String s = nickname;
            if(l.action==0)
            {
                s+="님이 들어왔습니다.";
            }else{
                s+="님이 나갔습니다.";
            }
            answer[k]=s;
            k++;
        }
        
        return answer;
    }
}
