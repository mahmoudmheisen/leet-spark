class Solution {
private:
    static bool my_compare(pair<int, string> i, pair<int, string> j) { 
        return i.first > j.first;
    }

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ret;
        vector<pair<int, string>> vec;
        int n = names.size();
        
        for(int i = 0; i < n; i++) {
            vec.push_back(make_pair(heights[i], names[i]));
        }
        
        sort(vec.begin(), vec.end(), my_compare);
        
        for(int i = 0; i < n; i++) {
            ret.push_back(vec[i].second);
        }
        
        return ret;
    }
};