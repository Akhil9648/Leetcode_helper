class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    j++;
                }
                string a=s.substr(i+1,j-i-1);
                if(mp.count(a)){
                    result+=mp[a];
                }
                else{
                    result+='?';
                }
                i=j;
            }
            else result+=s[i];
        }
        return result;
    }
};