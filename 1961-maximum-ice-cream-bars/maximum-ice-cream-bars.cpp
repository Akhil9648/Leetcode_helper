class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int a=*max_element(costs.begin(),costs.end());
        vector<int>count(a+1,0);
        for(auto it:costs){
            count[it]++;
        }
        for(int i=1;i<=a;i++){
            count[i]+=count[i-1];
        }
        int n=costs.size();
        vector<int>ans(n,0);
        for(auto it:costs){
            ans[count[it]-1]=it;
            count[it]--;
        }
        int cnt=0,sum=0;
        for(auto it:ans){
            sum+=it;
            if(sum>coins) return cnt;
            cnt++;
        }
        return cnt;
    }
};