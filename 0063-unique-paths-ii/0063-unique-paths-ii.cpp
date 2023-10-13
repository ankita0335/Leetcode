
class Solution {
public:
    int m,n;
    int dp[101][101];
    int solve(vector<vector<int>>&grid,int i,int j) {
        if(i<0 || j<0 || j>=n || i>=m || grid[i][j]==1 ) 
            return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=solve(grid, i,j+1);
        int d=solve(grid,i+1,j);
        return dp[i][j]= r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
}; 
