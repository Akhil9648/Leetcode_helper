class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto it:nums) arr.push_back(to_string(it));
        sort(arr.begin(),arr.end(),greater<string>());
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[j]+arr[i])>(arr[i]+arr[j])) swap(arr[i],arr[j]);
            }
        }
        string ans;
        for(auto it:arr){
            if(ans.size()==0 && it=="0") continue;
            ans+=it;
        }
        return ans.size()==0?"0":ans;
    }
};