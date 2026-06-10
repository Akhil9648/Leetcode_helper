class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree) {
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        //No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        //Complete Overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return min(a, b);
        }

        return max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};
class Solution {
public:
    typedef long long ll;
    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);   //true is for minimum
        SegmentTree maxST(nums, false);  //false is for maximum

        //{val, l, r} max. heap
        priority_queue<tuple<ll, int, int>> pq;

        //Step-1 (Initialize the heap with best value)
        //O(n*logn)
        for (int l = 0; l < n; l++) {  //l to n-1
            ll value = getValue(l, n - 1, minST, maxST, n);  //log(n)
            pq.push({value, l, n - 1});
        }

        //Step-2 Find top k
        ll result = 0;
        //O(k * log(n))
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nextBestValue = getValue(l, r - 1, minST, maxST, n);  //log(n)

            pq.push({nextBestValue, l, r - 1});  //log(n)
        }

        return result;

    }
};