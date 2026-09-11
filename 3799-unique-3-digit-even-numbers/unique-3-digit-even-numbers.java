class Solution {
    public int totalNumbers(int[] digits) {
        int cnt=0;
        int map[]=new int[10];
        Arrays.fill(map,0);
        for(int it:digits) map[it]++;
        for(int i=1;i<=9;i++){
            if(map[i]==0) continue;
            map[i]--;
            for(int j=0;j<=9;j++){
                if(map[j]==0) continue;
                map[j]--;
                for(int k=0;k<=8;k+=2){
                    if(map[k]>0){
                        cnt++;
                    }
                }
                map[j]++;
            }
            map[i]++;
        }
        return cnt;
    }
}