class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum=0;
        int n=cost.size();
        // if(n<=2){
        //     for(auto it:cost) sum+=it;
        //     return sum;
        // }
        int i=n-1;
        for(;i>1;i-=2){
            sum+=(cost[i]+cost[i-1]);
            i--;
        }
        while(i>=0){
            sum+=cost[i];
            i--;
        }
        return sum;
    }
};