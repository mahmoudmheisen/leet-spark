class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int sum = 0;
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = left; i <= right; i++) {
            if(find(begin(v), end(v), words[i][0]) != end(v) &&
              find(begin(v), end(v), words[i][words[i].size()-1]) != end(v)) sum++;
        }
        
        return sum;
    }
};