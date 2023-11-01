class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int maxCount = 0, currentCount = 0, prevVal = INT_MIN;
        findModeHelper(root, prevVal, currentCount, maxCount, result);
        return result;
    }

private:
    void findModeHelper(TreeNode* node, int& prevVal, int& currentCount, int& maxCount, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        findModeHelper(node->left, prevVal, currentCount, maxCount, result);
        if (node->val == prevVal) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        if (currentCount == maxCount) {
            result.push_back(node->val);
        } else if (currentCount > maxCount) {
            maxCount = currentCount;
            result = {node->val};
        }
        prevVal = node->val;
        findModeHelper(node->right, prevVal, currentCount, maxCount, result);
    }
};
