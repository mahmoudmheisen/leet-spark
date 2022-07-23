class Solution {
public:
    static bool compare(pair<int, string> a, pair<int, string> b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string, int> freq;
        vector<pair<int,string>> vec;

        for(string& word: words) {
            freq[word]++;
        }

        for(auto& item: freq) {
            vec.push_back({item.second, item.first});
        }
        
        sort(vec.begin(), vec.end(), compare);

        for(auto& item: vec) {
            if(k) {
                res.push_back(item.second);
                k--;
            }
        }

        return res;   
    }
};