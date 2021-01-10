function solution(number, k) {
    var answer = '';
    var num=number.split("");
    answer = number.substr(k);
    answer = answer.split("");
    
    for(var i=k-1;i>=0;i--)
    {
        for(var j=0;j<number.length-k;)
        {
            var temp = num[i];
            if(num[i]>=answer[j])
            {
                 num[i]=answer[j];
                 answer[j]=temp;
                j++;
            }else{
                break;
            }
        }
    }
    
    answer=answer.join("");
    
    return answer;
}
