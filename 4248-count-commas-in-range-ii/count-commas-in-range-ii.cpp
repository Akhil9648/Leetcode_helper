class Solution {
public:
    long long countCommas(long long n) {
        long long lower=1000;
        long long ans=0;
        int comma=1;
        while(lower<=n){
            long long upper=(lower*1000)-1;
            if(upper>n) upper=n;
            long long cnt=upper-lower+1;
            ans+=(cnt*comma);
            lower*=1000;
            comma++;
        }
        return ans;
    }
};