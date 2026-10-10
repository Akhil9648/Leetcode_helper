class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // Map to store the frequency of each absolute difference
        unordered_map<int, int> freq;
        int n = nums1.size();
        
        for (int i = 0; i < n; i++) {
            freq[abs(nums1[i] - nums2[i])]++;
        }
        
        // Max-heap storing pairs of {difference, frequency}
        priority_queue<pair<int, int>> pq;
        for (auto& it : freq) {
            if (it.first > 0) { // No need to track 0 differences
                pq.push({it.first, it.second});
            }
        }
        
        long long k = (long long)k1 + k2;
        
        while (k > 0 && !pq.empty()) {
            auto [diff, count] = pq.top();
            pq.pop();
            
            // Determine the next largest difference in the heap
            int next_diff = !pq.empty() ? pq.top().first : 0;
            
            // How much we need to subtract from all 'count' elements 
            // to bring them down to match 'next_diff'
            long long diff_gap = diff - next_diff;
            long long total_ops_needed = count * diff_gap;
            
            if (k >= total_ops_needed) {
                // We have enough k to flatten all current maximums down to next_diff
                k -= total_ops_needed;
                if (next_diff > 0) {
                    // Merge them into the existing next_diff elements
                    auto [next_d, next_c] = pq.top();
                    pq.pop();
                    pq.push({next_d, next_c + count});
                }
            } else {
                // We don't have enough k to flatten them completely.
                // Distribute k operations across the 'count' elements.
                long long decrease_by = k / count;
                long long remainder = k % count;
                
                if (diff - decrease_by > 0) {
                    pq.push({diff - decrease_by, count - remainder});
                }
                if (diff - decrease_by - 1 > 0) {
                    pq.push({diff - decrease_by - 1, remainder});
                }
                k = 0; // All operations used up
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        while (!pq.empty()) {
            auto [diff, count] = pq.top();
            pq.pop();
            ans += 1LL * count * diff * diff;
        }
        
        return ans;
    }
};
