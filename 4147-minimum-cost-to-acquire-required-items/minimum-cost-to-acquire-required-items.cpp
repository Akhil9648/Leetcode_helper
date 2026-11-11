class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth<=cost1+cost2){
            long long a=0;
            int need=min(need1,need2);
            a+=1LL*costBoth*need;
            if(need1>need){
                a+=1LL*min(costBoth,cost1)*(need1-need);
            }
            if(need2>need){
                a+=1LL*min(costBoth,cost2)*(need2-need);
            }
            return a;
        }
        long long ans=0;
        ans+=1LL*cost1*need1;
        ans+=1LL*cost2*need2;
        return ans;
    }
};