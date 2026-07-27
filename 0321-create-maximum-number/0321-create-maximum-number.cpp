class Solution {
public:
    // Helper 1: Return the maximum subsequence of length len
    vector<int> maxSubsequence(vector<int>& nums, int len) {
        int drop = nums.size() - len;
        stack<int> st;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.top() < num) {
                st.pop();
                drop--;
            }
            st.push(num);
        }

        while (st.size() > len)
            st.pop();

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }

    // Helper 2: Compare remaining suffixes
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    // Helper 3: Merge two subsequences
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans;

        int start = max(0, k - n);
        int end = min(k, m);

        for (int i = start; i <= end; i++) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);

            vector<int> candidate = merge(part1, part2);

            if (candidate > ans)
                ans = candidate;
        }

        return ans;
    }
};