class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, int> memo;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            memo[nums2[i]] = !st.empty() ? st.top(): -1;
            st.push(nums2[i]);
        }

        for(int i = 0; i<nums1.size(); i++) {
            res[i] = memo[nums1[i]];
        }

        return res;
    }
};