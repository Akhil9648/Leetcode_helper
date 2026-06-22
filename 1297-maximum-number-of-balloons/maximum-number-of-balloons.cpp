class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        int mini=INT_MAX,minio=INT_MAX;
        for(auto it:text){
            if(it=='b' || it=='a' || it=='l' || it=='o' || it=='n') mp[it]++;
        }
        if(mp.size()<5) return 0;
        for(auto it:mp){
            mini=min(mini,it.second);
            if(it.first=='l' || it.first=='o'){
                minio=min(minio,it.second);
            }
        }
        if(mini==INT_MAX) return 0;
        if(minio>=mini*2) return mini;
        return minio/2;
    }
};