class Solution1 {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                for(int k=0;k<=limit;k++){
                    if(i+j+k==n) cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution2 {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                int a=n-(i+j);
                if(a<=limit && a>=0) cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int solve(int n,int limit,int child){
        if(n==0 && child==0) return 1;
        if(child==0) return 0;
        int ans=0;
        for(int i=0;i<=limit;i++){
            if(n>=i) ans+=solve(n-i,limit,child-1);
        }
        return ans;
    }
    int distributeCandies(int n, int limit) {
        return solve(n,limit,3);
    }
};