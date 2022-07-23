class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> freq;
        priority_queue<pair<int,int>> pq;
        
        for(int num: nums) {
            freq[num]++;
        }
        
        for(auto& item: freq) {
            pq.push(make_pair(item.second, item.first));
        }
                
        while(k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res; 
    }
};