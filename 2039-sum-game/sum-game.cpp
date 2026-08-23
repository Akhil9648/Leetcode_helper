class Solution {
public:
    bool sumGame(string num) {
        int lsum=0,rsum=0,lq=0,rq=0;
        int n=num.size();
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') lq++;
            else lsum+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') rq++;
            else rsum+=(num[i]-'0');
        }
        double l=lsum+(lq*4.5);
        double r=rsum+(rq*4.5);
        return l!=r;

    }
};