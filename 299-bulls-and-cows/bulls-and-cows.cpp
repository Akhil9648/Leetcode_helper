class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,unordered_set<int>>mp;
        int n=secret.size();
        for(int i=0;i<n;i++){
            mp[secret[i]].insert(i);
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(mp.count(guess[i])){
                if(mp[guess[i]].count(i)){
                    mp[guess[i]].erase(i);
                    if(mp[guess[i]].size()==0) mp.erase(guess[i]);
                    a++;
                    guess[i]+='9';
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<guess[i]<<" ";
            if(mp.count(guess[i])){
                mp[guess[i]].erase(mp[guess[i]].begin());
                if(mp[guess[i]].size()==0) mp.erase(guess[i]);
                b++;
            }
        }
        string ans;
        ans+=to_string(a)+'A'+to_string(b)+'B';
        return ans; 
    }
};