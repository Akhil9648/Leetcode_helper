class Solution {
public:
    long long smallestNumber(long long num) {
        int flag=0;
        if(num<0) flag=1;
        vector<int>ans;
        while(num){
            int d=num%10;
            ans.push_back(abs(d));
            num/=10;
        }
        long long res=0;
        sort(ans.begin(),ans.end());
        if(flag){
            reverse(ans.begin(),ans.end());
            for(auto it:ans) res=res*10+it;
            return -1*res;
        }

        int n=ans.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            res=res*10+ans[i];
            if(ans[i]==0) cnt++;
            else{
                while(cnt>0){
                    res=res*10;
                    cnt--;
                }
            }
            cout<<res;
        }
        return res;
    }
};