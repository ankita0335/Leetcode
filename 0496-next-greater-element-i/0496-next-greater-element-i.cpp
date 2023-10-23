class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                v.push_back(-1);
            } else {
                v.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(v.begin(), v.end());
        vector<int> res;
        for (int num : nums1) {
            int i = find(nums2.begin(), nums2.end(), num) - nums2.begin();
            res.push_back(v[i]);
        }

        return res;
    }
};
