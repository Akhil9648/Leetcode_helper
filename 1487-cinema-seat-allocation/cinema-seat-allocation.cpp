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