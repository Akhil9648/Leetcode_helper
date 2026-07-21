class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int activeCount = count(begin(s), end(s), '1');

        vector<int> inactiveBlocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;

                inactiveBlocks.push_back(i-start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        for(int i = 1; i < inactiveBlocks.size(); i++) {
            maxPairSum = max(maxPairSum, inactiveBlocks[i] + inactiveBlocks[i-1]);
        }

        return maxPairSum + activeCount;
    }
};