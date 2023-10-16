class Solution {
public:
    vector<int> getRow(int idx) {
        vector<vector<int>> res(idx + 1);
        
        for (int i = 0; i <= idx; i++) {
            res[i] = vector<int>(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res[idx];
    }
};
