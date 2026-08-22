class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int mul=1;
        while(num){
            int d=num%10;
            sum+=d;
            mul*=d;
            num/=10;
        }
        return (n%(sum+mul)==0);
    }
};