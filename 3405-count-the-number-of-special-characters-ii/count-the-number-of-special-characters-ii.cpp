class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp1,mp2;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
                if(mp1.count(word[i])) continue;
                else mp1[word[i]]=i;
            }
            else mp2[word[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp1.count(word[i]-32)){
                if(mp2[word[i]]<mp1[word[i]-32]){
                    cnt++;
                    mp1.erase(word[i]-32);
                    mp2.erase(word[i]);
                }
            }
        }
        return cnt;
    }
};