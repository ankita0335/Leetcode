class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<int>&v,int u,int n){
        v[u]=1;
        for(int j=0;j<n;j++){
            if(u!=j && isConnected[u][j]==1){
                if(!v[j]){
                    dfs(isConnected,v,j,n);
                }
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int c=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(!v[i]){
                c++;
                dfs(isConnected,v,i,n);
            }
        }
        return c;
    }
};