/*
문자열 비교
equals : String 클래스는 Object의 equals()를 오버라이드하여 인자로 전달된 String의 문자열을 비교
compareTo : 어떤 문자가 사전적인 순서로 앞에 있는지도 리턴. 음수, 0(동일), 양수

*/

class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        int idx=0;
        
        for(int i=0; i<seoul.length; i++){
            if(seoul[i].equals("Kim")){
                idx=i;
                break;
            }
        }
        
        answer = "김서방은 "+idx+"에 있다";
        
        return answer;
    }
}
