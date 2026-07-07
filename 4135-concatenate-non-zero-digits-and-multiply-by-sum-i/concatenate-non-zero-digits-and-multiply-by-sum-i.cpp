class Solution {
public:
    long long sumAndMultiply(int n) {
        string a=to_string(n);
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                a.erase(a.begin()+i);
                i--;
            }
        }
        long long x=0;
        long long sum=0;
        for(char c:a){
            x=x*10+(c-'0');
            sum+=(c-'0');
        }
        return x*sum;
    }
};