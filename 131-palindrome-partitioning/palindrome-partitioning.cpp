class Solution {
public:
    int n;
    bool check(string &curr){
        int i=0,j=curr.size()-1;
        while(i<=j){
            if(curr[i]!=curr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string& s,vector<vector<string>>& ans,string curr,vector<string> a){
        if(i>=n){
            if(curr.size()>0 && check(curr)) a.push_back(curr);
            if(a.size()>0) ans.push_back(a);
            return;
        }
        for(int j=i;j<n;j++){
            curr+=s[j];
            if(check(curr)){
                a.push_back(curr);
                solve(j+1,s,ans,"",a);
                a.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        //your code goes here
        n=s.size();
        vector<string>a;
        vector<vector<string>>ans;
        solve(0,s,ans,"",a);
        return ans;
    }
};