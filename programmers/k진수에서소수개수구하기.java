import java.util.*;

class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        String tmp = makeK(n,k);
        String[] parsed = tmp.split("0+");
        for(int i=0;i<parsed.length;i++){
            if(isPrime(Long.parseLong(parsed[i]))){
                answer++;
            }
        }
        return answer;
    }
    
    public String makeK(int n, int k){
        String ret = "";
        while(n != 0){
            ret += Integer.toString(n%k);
            n /= k;
        }
        StringBuffer sb = new StringBuffer(ret);
        return sb.reverse().toString();
    }
    
    public boolean isPrime(Long n){
        if(n == 1){
            return false;
        }
        for(long i=2;i*i<=n;i++){
            if(n % i == 0){
                return false;
            } 
        }
        return true;
    }
}
