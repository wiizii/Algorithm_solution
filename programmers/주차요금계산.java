import java.util.*;

class Solution {
    TreeSet<Integer> car = new TreeSet<Integer>();
    int[] inCar = new int[10001];
    int[] outCar = new int[10001];
    int[] total = new int[10001];
    int lastTime = 24 * 60 - 1;
    
    public int[] solution(int[] fees, String[] records) {
        for(int i=0;i<records.length;i++){
            String[] data = records[i].split(" ");
            String[] t = data[0].split(":");
            int carNum = Integer.parseInt(data[1]);
            int ttoi = Integer.parseInt(t[0])*60 + Integer.parseInt(t[1]);
            car.add(carNum);
            if(data[2].equals("IN")){
                if(outCar[carNum] != 0){
                    total[carNum] += outCar[carNum] - inCar[carNum];
                }
                inCar[carNum] = ttoi;
            }
            if(data[2].equals("OUT")){
                outCar[carNum] = ttoi;
            }
        }
        
        int[] answer = new int[car.size()];
        int idx = 0;
        for(int c : car){
            int money = fees[1];
            int between = 0;
            if(outCar[c] == 0 || inCar[c] > outCar[c]){
                between = lastTime - inCar[c];
            }
            else{
                between = outCar[c] - inCar[c];
            }
            total[c] += between;
            if(total[c] > fees[0]){
                money += Math.ceil((double)(total[c] - fees[0]) / fees[2]) * fees[3];
            }
            answer[idx++] = money;
        }
        
        return answer;
    }
}
