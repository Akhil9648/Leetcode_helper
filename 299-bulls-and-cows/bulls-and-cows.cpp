class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int n=secret.size();
        for(int i=0;i<n;i++){
            mp[secret[i]]++;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                mp[secret[i]]--;
                a++;
                guess[i]+='9';
            }
        }
        for(int i=0;i<n;i++){
            cout<<guess[i]<<" ";
            if(mp[guess[i]]>0){
                mp[guess[i]]--;
                b++;
            }
        }
        string ans;
        ans+=to_string(a)+'A'+to_string(b)+'B';
        return ans; 
    }
};