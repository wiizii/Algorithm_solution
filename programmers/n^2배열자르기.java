import java.util.*;

class Solution {
    public List<Integer> solution(int n, long left, long right) {
        ArrayList<Integer> arr = new ArrayList<>();
        int sx = (int)(left/n+1), sy = (int)(left%n);
        int ex = (int)(right/n+1), ey = (int)(right%n);
        for(int i = sx; i <= ex; i++){
            for(int j = 1; j < i; j++)
                arr.add(i);
            for(int j = i; j <= n; j++)
                arr.add(j);
        }
        
        return arr.subList(sy, arr.size()-n+ey+1);
    }
}