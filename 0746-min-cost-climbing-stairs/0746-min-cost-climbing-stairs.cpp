class Solution {
public:
    int mincost(vector<int>& cost, int n, vector<int>& dp) {
        if (dp[n] != -1) {
            return dp[n];
        }
        if (n <= 1) {
            return dp[n] = 0;
        }
        if (n == 2) {
            return dp[n] = min(cost[0], cost[1]);
        } else {
            return dp[n] = min(mincost(cost, n - 1, dp) + cost[n - 1], mincost(cost, n - 2, dp) + cost[n - 2]);
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1); 
        return mincost(cost, n, dp);
    }
};
