class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while(sum>0 && num>0){
            int a=min(9,sum);
            sum-=a;
            ans+=to_string(a);
            num--;
        }
        while(num>0){
            ans+='0';
            num--;
        }
        if(num>0 || sum>0) return "";
        return ans;
    }
};