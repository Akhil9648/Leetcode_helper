class Solution {
public:
    int findMin(vector<int>& nums) {
        int si = 0, ei = nums.size() - 1;

        // Continue until only one element remains.
        while (si < ei) {
            int mid = si + (ei - si) / 2;

            // If nums[mid] > nums[ei],
            // the minimum lies in the right half.
            if (nums[mid] > nums[ei]) {
                si = mid + 1;
            }

            // If nums[mid] < nums[ei],
            // the minimum lies in the left half (including mid).
            else if (nums[mid] < nums[ei]) {
                ei = mid;
            }

            // If nums[mid] == nums[ei],
            // we cannot determine the side,
            // so safely shrink the search space.
            else {
                ei--;
            }
        }

        // si == ei, both point to the minimum element.
        return nums[si];
    }
};