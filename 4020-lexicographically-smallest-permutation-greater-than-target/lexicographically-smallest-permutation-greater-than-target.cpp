class Solution {
public:
    string result;
    int n;
    bool solve(int i,string curr,vector<int>& freq,string & target,bool gr){
        if(i>=n){
            if(gr){
                result=curr;
                return true;
            }
            return false;
        }
        if(gr){
            for(char c='a';c<='z';c++){
                if(freq[c-'a']>0){
                    curr.push_back(c);
                    freq[c-'a']--;
                    return solve(i+1,curr,freq,target,gr);
                }
            }
        }
        for(char c=target[i];c<='z';c++){
            if(freq[c-'a']==0) continue;
            curr.push_back(c);
            freq[c-'a']--;
            bool isg=gr|| (c>target[i]);
            if(solve(i+1,curr,freq,target,isg)) return true;
            curr.pop_back();
            freq[c-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        n=s.size();
        vector<int>freqs(26,0);
        for(auto it:s){
            freqs[it-'a']++;
        }
        solve(0,"",freqs,target,false);
        return result;
    }
};