#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int sum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create a collection tracking pairs of {original_value, original_index}
        vector<pair<int, int>> sorted_arr(n);
        for (int i = 0; i < n; i++) {
            sorted_arr[i] = {nums[i], i};
        }

        // Step 2: Fix the lambda sorting logic to sort by digit sum first
        sort(sorted_arr.begin(), sorted_arr.end(), [this](const auto &p1, const auto &p2) {
            int sa = sum(p1.first);
            int sb = sum(p2.first);
            if (sa != sb) return sa < sb; // Sort by digit sum ascending
            return p1.first < p2.first;   // Tie-breaker: sort by numerical value ascending
        });

        // Step 3: Use Cycle Detection to calculate the exact minimum swaps required
        vector<bool> visited(n, false);
        int total_swaps = 0;

        for (int i = 0; i < n; i++) {
            // If already visited or already in the correct sorted spot, skip it
            if (visited[i] || sorted_arr[i].second == i) {
                continue;
            }

            // Calculate the size of the current permutation cycle
            int cycle_size = 0;
            int current_idx = i;
            
            while (!visited[current_idx]) {
                visited[current_idx] = true;
                current_idx = sorted_arr[current_idx].second; // Jump to where this element belongs
                cycle_size++;
            }

            if (cycle_size > 1) {
                total_swaps += (cycle_size - 1);
            }
        }

        return total_swaps;
    }
};
