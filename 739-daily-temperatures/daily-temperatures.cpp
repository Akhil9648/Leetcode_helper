class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        int i=0;
        vector<int>ans(n,0);
        while(i<n){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};