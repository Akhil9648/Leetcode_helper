class Solution {
public:
    string result;
    char odc;
    int n;
    bool solve(int i,string &target,vector<int>& freq,string curr,bool isg){
        if(i==(n/2)){
            string rev=curr;
            reverse(rev.begin(),rev.end());
            if(!isg) {
                string ans = curr + (n % 2 == 1 ? string(1, odc) : "") + rev;
                if(ans > target) {
                    result = ans;
                    return true;
                }
                return false;
            }
            if(n%2==1){
                string ans=curr+odc+rev;
                result=ans;
            }
            else{
                string ans=curr+rev;
                result=ans;
            }
            return true;
        }
        if(isg){
            for(char c='a';c<='z';c++){
                if(freq[c-'a']<=1) continue;
                curr.push_back(c);
                freq[c-'a']-=2;
                if(solve(i+1,target,freq,curr,isg)) return true;
                freq[c - 'a'] += 2;
                curr.pop_back();
            }
            return false;
        }
        for(char c=target[i];c<='z';c++){
            if(freq[c-'a']<=1) continue;
            curr.push_back(c);
            bool igr=isg||(c>target[i]);
            freq[c-'a']-=2;
            if(solve(i+1,target,freq,curr,igr)) return true;
            curr.pop_back();
            freq[c-'a']+=2;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        n=s.size();
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                if(flag) return "";
                odc=i+'a';
                freq[i]-=1;
                flag=1;
            }
        }
        solve(0,target,freq,"",false);
        return result;
    }
};