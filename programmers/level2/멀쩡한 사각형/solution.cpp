/*
최대공약수 gcd : 유클리드호제법
최대공배수 = n/gcd
*/

using namespace std;

//최대공약수
int gcd(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    int i_gcd = gcd(w,h);
    int s_w = w/i_gcd;
    int s_h = h/i_gcd;
    
    answer = (long long)w*h-(s_w+s_h-1)*i_gcd;
    
    
    return answer;
}
