class Solution {
public:
    void fun(int i, vector<int> curr, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        fun(i + 1, curr, nums, res);
        curr.pop_back();
        fun(i + 1, curr, nums, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        fun(0, curr, nums, res);
        return res;
    }
};
