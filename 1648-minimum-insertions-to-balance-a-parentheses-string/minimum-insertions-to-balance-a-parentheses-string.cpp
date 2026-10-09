class Solution {
public:
    int minInsertions(string s) {
        stack<int>st;
        int ans=0,curr=0;
        for(auto it:s){
            if(it=='('){
                if(!st.empty()){
                    int a=st.top();
                    if(a<0){
                        ans+=(abs(a)+1)/2;
                        st.pop();
                    }
                    else if(a==1){
                        ans++;
                        st.pop();
                    }
                }
                st.push(2);
            }
            else{
                if(!st.empty()){
                    if(st.top()==1) st.pop();
                    else if(st.top()==2){
                        st.pop();
                        st.push(1);
                    }
                }
                else{
                    ans++;
                    st.push(1);
                }
            }
        }
        while(!st.empty()){
            int a=st.top();
            ans+=a;
            st.pop();
        }
        return ans;
    }
};