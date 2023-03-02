class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret;
        ret.push_back(pref[0]);
    
        int temp = ret[0];
        for(int i = 1; i < pref.size(); i++) {
            int ans = pref[i];
            
            ans ^= temp;
            
            ret.push_back(ans);
            temp ^= ret[i];
        }
        
        return ret;
    }
};
