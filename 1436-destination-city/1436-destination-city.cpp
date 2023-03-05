class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> srcs;
        for(auto &path : paths) srcs.insert(path[0]);
        
        for(auto &path : paths) {
            if(!srcs.count(path[1])) return path[1];
        }
        
        return "";
    }
};
