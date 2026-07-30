class Solution1 {
public:
    int mini=INT_MAX,n;
    unordered_set<string>st;
    bool valid(string &curr){
        stack<char>st;
        for(auto it:curr){
            if(it==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else return false;
            }
            else if(it=='(') st.push(it);
        }
        return st.empty();
    }
    void solve(int i,string &s,vector<string>& ans,string &curr){
        if(i>=n){
            if(!valid(curr)  || st.count(curr)) return ;
            if(n-curr.size()<mini){
                ans.clear();
                ans.push_back(curr);
                st.insert(curr);
                mini=n-curr.size();
            }
            else if(n-curr.size()==mini){
                st.insert(curr);
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(s[i]);
        solve(i+1,s,ans,curr);
        curr.pop_back();
        solve(i+1,s,ans,curr);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        string curr;
        n=s.size();
        solve(0,s,ans,curr);
        return ans;
    }
};
class Solution {
public:
    int mini=INT_MAX,n;
    unordered_set<string>st;
    bool valid(string &curr){
        stack<char>st;
        for(auto it:curr){
            if(it==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else return false;
            }
            else if(it=='(') st.push(it);
        }
        return st.empty();
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        string curr;
        int n=s.size();
        bool find=0;
        queue<string>q;
        q.push(s);
        unordered_set<string>vis;
        vis.insert(s);
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(valid(curr)){
                find=1;
                ans.push_back(curr);
            }
            if(find) continue;
            for(int i=0;i<curr.size();i++){
                if(curr[i]!='(' && curr[i]!=')') continue;
                string temp=curr.substr(0,i)+curr.substr(i+1);
                if(!vis.count(temp)){
                    q.push(temp);
                    vis.insert(temp);
                }
            }
        }
        return ans;
    }
};