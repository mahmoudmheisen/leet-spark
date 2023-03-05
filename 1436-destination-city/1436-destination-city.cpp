class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        string str = "";
        bool found = false;
        
        for(int i = 0; i < n; i++) {
            str = paths[i][1];
            found = false;

            for(int j = 0; j < n && !found; j++) {
                if(paths[j][0] == str) {
                    found = true;
                }
            }
            
            if(!found) break;
        }
        
        return str;
    }
};
