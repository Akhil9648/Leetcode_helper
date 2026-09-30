class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt=0;
        for(auto  it:hours){
            if(it>=target) cnt++;
        }
        return cnt;
    }
};