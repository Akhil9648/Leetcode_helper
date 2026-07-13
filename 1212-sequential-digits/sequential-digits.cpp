class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int a=floor(log10(low)) + 1;
        int b=floor(log10(high)) + 1;
        vector<int>ans;
        string curr="123456789";
        for(int i=0;i<9;i++){
            for(int j=a;j<=min(b,9-i);j++){
                string u=curr.substr(i,j);
                int num=stoi(u);
                if(num<low) continue;
                if(num>high) break;
                ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};