class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int>c_to_p;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int node=i;
            int left=leftChild[i];
            int right=rightChild[i];
            if(left!=-1){
                adj[node].push_back(left);
                if(c_to_p.find(left)!=c_to_p.end(left)){
                    return false;
                }
                c_to_p[left]=node;
            }
            if(right!=-1){
                adj[node].push_back(right);
                if(c_to_p.find(right)!=c_to_p.end(right)){
                    return false;
                }
                c_to_p[right]=node;
            }
        }
        int root=-1;
        for (int i = 0; i < n; i++) {
            if (c_to_p.find(i) == c_to_p.end()) {
                if (root != -1) {
                    // If already found a root
                    return false;
                }
                root = i;
            }
        }
        if(root==-1)    return false;
        int c=0;
        queue<int>q;
        vector<bool>v(n,false);
        q.push(root);
        c=1;
        v[root]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &v1:adj[node]){
                if(v[v1]==true){
                    return false;
                }
                if(!v[v1]){
                    v[v1]=true;
                    c++;
                    q.push(v1);
                }
            }
        }
        return c==n;
    }
};

