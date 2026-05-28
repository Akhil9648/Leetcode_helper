class Solution {
public:
    bool compare(string &a,string &b){
        int a1=a.size();
        int b1=b.size();
        int i=0;
        while(i<min(a1,b1)){
            if(a[i]>b[i]) return false;
            else if(a[i]<b[i]) return true;
            i++;
        }
        int j=i-1;
        if(a1>b1){
            while(i<a1){
                if(a[i]>b[j]) return false;
                else if(a[i]<b[j]) return true;
                i++;
            }
        }
        else if(a1<b1){
            while(i<b1){
                if(a[j]>b[i]) return false;
                else if(a[j]<b[i]) return true;
                i++;
            }
        }
        return false;
    }
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