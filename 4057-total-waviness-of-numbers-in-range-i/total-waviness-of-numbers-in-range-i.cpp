class Solution {
public:
    int count(string a){
        int n=a.size();
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string a=to_string(i);
            ans+=count(a);
        }
        return ans;
    }
};