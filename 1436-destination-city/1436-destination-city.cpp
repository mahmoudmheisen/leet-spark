class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> srcs;
        
        for(auto &p : paths) srcs.insert(p[0]);
        for(auto &p : paths) if(!srcs.count(p[1])) return p[1];
        
        return "";
    }
};
