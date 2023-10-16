class Solution {
public:
    vector<int> getRow(int idx) {
        vector<int> v(idx + 1);
        v[0] = 1;
        for (int i = 1; i <= idx; i++) {
            v[i] = 1; 
            for (int j = i - 1; j > 0; j--) {
                v[j] = v[j] + v[j - 1];
            }
        }
        return v;
    }
};
