class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res;
        unordered_map<int, queue<int>> mapper;
        
        for (int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            mapper[groupSize].push(i);
        }
        
        for (auto &it : mapper) {
            int size = it.first;
            queue<int> q = it.second;
            
            while(!q.empty()) {
                vector<int> temp;
                
                for (int i = 0; i < size; i++) {
                    temp.push_back(q.front());
                    q.pop();
                }
                
                res.push_back(temp);
            }
            
        }
        
        return res;
    }
};