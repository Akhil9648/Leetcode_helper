class Solution {
public:
    int GCD(int a,int b){
        if(b==0) return a;
        return GCD(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int odd=0,even=0,it=0;
        while(it<=n*2){
            if(it%2==1) odd+=it;
            else even+=it;
            it++;
        }
        return GCD(odd,even);
    }
};