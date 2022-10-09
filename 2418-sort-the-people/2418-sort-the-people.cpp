class Solution {
private:
    static bool my_compare(pair<int, string> i, pair<int, string> j) { 
        return i.first > j.first;
    }

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ret;
        map<int, string, greater<int>> mapper;
        int n = names.size();
        
        for(int i = 0; i < n; i++) {
            mapper[heights[i]] = names[i];
        }
                
       for(auto i : mapper){
            ret.push_back(i.second);
        }
        return ret;
    }
};