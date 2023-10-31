class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>v;
        int res=0;
        v.push_back(pref[0]);
        for(int i=1;i<pref.size();i++)
        {
            res=pref[i]^pref[i-1];    
            v.push_back(res);
        }
        return v;
    }
};