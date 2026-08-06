class Solution {
public:
    int findmul(int n){
        int sum=1;
        while(n){
            int d=n%10;
            sum*=d;
            n/=10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        while(findmul(n)%t!=0) n++;
        return n;
    }
};