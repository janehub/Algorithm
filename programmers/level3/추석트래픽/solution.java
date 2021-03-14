import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Calendar;
import java.util.ArrayList;

class Job{
    Date start_dt;
    Date end_dt;
    
    Job(Date a, Date b)
    {
        start_dt=a;
        end_dt=b;
    }
    
}

class Solution {
    
    ArrayList<Job> list;
    
    boolean isOver(Job job) //1초전 계산
    {
        return true;
    }
    
    int calTP()    //처리량 계산
    {
        int max_cnt=1;
        Calendar calendar=Calendar.getInstance();
        
        for(int i=0;i<list.size();i++)
        {
            int cnt1=1;
            int cnt2=1;
            Job job=list.get(i);
            Date gu_st = job.start_dt;
            Date gu_end= job.end_dt;
  
            calendar.setTime(job.start_dt);
            calendar.add(Calendar.MILLISECOND, -999);
            Date gu_st_bf = calendar.getTime();
            
            calendar.setTime(job.end_dt);
            calendar.add(Calendar.MILLISECOND, 999);
            Date gu_end_af=calendar.getTime();
            
            for(int j=0;j<list.size();j++)
            {
                if(j==i)
                    continue;
                
                Job job2=list.get(j);
                Date start = job2.start_dt;
                Date end = job2.end_dt;
                if(start.compareTo(gu_end_af)<=0 && end.compareTo(gu_end)>=0)
                {
                    cnt1++;
                }
                if(start.compareTo(gu_st)<=0 && end.compareTo(gu_st_bf)>=0)
                {
                    cnt2++;
                }
            }
            max_cnt=Math.max(Math.max(cnt1,cnt2),max_cnt);
        }
        
        return max_cnt;
    }
    
    public int solution(String[] lines) {
        int answer = 0;
        Calendar calendar=Calendar.getInstance();
        list = new ArrayList<>();
        
        if(lines.length==0)
        {
            return 0;
        }else if(lines.length==1)
        {
            return 1;
        }
        
        for(String l:lines)
        {
            String end_t=l.substring(0,23);
            String s_t=l.substring(24,l.length()-1);
            int t=(int)(Double.parseDouble(s_t)*1000);
            SimpleDateFormat df= new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
            try{
                Date end_d=df.parse(end_t);
                calendar.setTime(end_d);
                calendar.add(Calendar.MILLISECOND, -t+1);
                Date start_d=calendar.getTime();
                list.add(new Job(start_d,end_d));
                
            }catch(Exception e)
            {
                e.printStackTrace(); 
            }
            
            
        }
        
        answer = calTP();
        
        return answer;
    }
}
