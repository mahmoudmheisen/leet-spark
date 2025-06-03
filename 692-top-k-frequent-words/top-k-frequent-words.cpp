class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> ht;
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype([](const pair<string, int>& a,
                          const pair<string, int>& b) {
                           if (a.second == b.second) {
                               return a.first < b.first;
                           }
                           return a.second > b.second;
                       })>
            minHeap;

        for (string word : words) {
            if (ht.count(word))
                ht[word]++;
            else
                ht[word] = 1;
        }

        for (auto pair : ht) {
            minHeap.push(pair);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};