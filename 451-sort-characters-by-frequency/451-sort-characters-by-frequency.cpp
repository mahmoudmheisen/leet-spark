typedef pair<char, int> pqPair;

class compare {
public:
  compare() {}
  bool operator() (const pqPair& lhs, const pqPair& rhs) const {
    return lhs.second < rhs.second;
  }
};

class Solution {
public:
  string frequencySort(string s) {
    map<char, int> dict;
    priority_queue<pqPair, vector<pqPair>, compare> pq;
    stringstream ss;
    string res;
    
    for (char c : s) {
      if (!dict[c]) dict[c] = 1;
      else dict[c]++;
    }
    
    for (pqPair pair : dict) pq.push(pair);
    
    while (pq.size()) {
      for (int i = 0; i < pq.top().second; i++) ss << pq.top().first;
      pq.pop();
    }
    
    ss >> res;
    return res;
  }
};


