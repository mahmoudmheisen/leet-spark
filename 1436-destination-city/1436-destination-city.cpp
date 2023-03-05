class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        string ret = paths[0][1];
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            string str = paths[i][1];
            for(int j = 0; j < n; j++) {
                if(paths[j][0] == str) continue;
                else count++;
                if(count == n) return str;
            }
        }
        
        return ret;
    }
};
