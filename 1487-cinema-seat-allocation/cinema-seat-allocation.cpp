class Solution1 {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>>res(n,vector<int>(10,1));
        for(auto it:reservedSeats){
            res[it[0]-1][it[1]-1]=0;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int one=0,tw=0,th=0;
            if(res[i][1] && res[i][2] && res[i][3] && res[i][4]) {
                one++;
            }
            if(res[i][3] && res[i][4] && res[i][5] && res[i][6]){
                tw++;
            }
            if(res[i][5] && res[i][6] && res[i][7] && res[i][8]){
                th++;
            }
            if((one && tw && th) || (one && th)) cnt+=2;
            else if((one && tw) || (tw && th) || one || tw || th) cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mn;
        for(auto it:reservedSeats){
            mn[it[0]].insert(it[1]);
        }
        int cnt=n*2;
        for(auto const &[a,mp]:mn){
            int one=0,tw=0,th=0;
            if(!mp.count(2) && !mp.count(3) && !mp.count(4) && !mp.count(5)) {
                one++;
            }
            if(!mp.count(4) && !mp.count(5) && !mp.count(6) && !mp.count(7)){
                tw++;
            }
            if(!mp.count(6) && !mp.count(7) && !mp.count(8) && !mp.count(9)){
                th++;
            }
            int d=0;
            if((one && tw && th) || (one && th)) d=2;
            else if((one && tw) || (tw && th) || one || tw || th) d=1;
            cnt-=(2-d);
        }
        return cnt;
    }
};