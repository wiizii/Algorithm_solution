class Solution {
    int answer = 0;
    boolean[] check = new boolean[8];
    
    public void solve(int k, int cnt, int[][] dungeons){
        answer = Math.max(answer, cnt);
        
        for(int i=0;i<dungeons.length;i++){
            if(!check[i]){
                check[i] = true;
                if(k >= dungeons[i][0])
                    solve(k-dungeons[i][1], cnt+1, dungeons);
                check[i] = false; 
            }
        }
    }
    
    public int solution(int k, int[][] dungeons) {
        solve(k, 0, dungeons);
        return answer;
    }
}