class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        int m=people.size();
        vector<int>st(n);
        vector<int>et(n);
        vector<int>res(m);
        for(int i=0;i<n;i++){
            st[i]=flowers[i][0];
            et[i]=flowers[i][1];
        }
        sort(begin(st),end(st));
        sort(begin(et),end(et));
        for(int i=0;i<m;i++){
            int time=people[i];
            int bloomed=upper_bound(begin(st),end(st),time)-begin(st);
            int died=lower_bound(begin(et),end(et),time)-begin(et);
            res[i]=bloomed-died;
        }
        return res;
    }
};

