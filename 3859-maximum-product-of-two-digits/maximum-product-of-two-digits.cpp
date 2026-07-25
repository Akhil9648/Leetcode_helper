class Solution {
public:
    int maxProduct(int n) {
        int a=0,b=0;
        while(n){
            int d=n%10;
            if(d>b){
                if(d>a){
                    b=a;
                    a=d;
                }
                else b=d;
            }
            n/=10;
        }
        return a*b;
    }
};