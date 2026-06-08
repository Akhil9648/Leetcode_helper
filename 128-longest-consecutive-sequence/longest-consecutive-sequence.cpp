class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        if(st.empty()) return 0;
        int prev=*st.begin(),cnt=0,curr=1;
        // cout<<prev<<" ";
        for(auto it:st){
            if(it!=prev+1){
                cnt=max(cnt,curr);
                curr=1;
                prev=it;
            }
            else{
                prev=it;
                curr++;
            }
            cout<<it<<" ";
        }
        cnt=max(cnt,curr);
        return cnt;
    }
};