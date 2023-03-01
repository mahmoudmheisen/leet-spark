class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        
        for(string word : words) {
            if(!s.rfind(word, 0)) count++;
        }
        
        return count;
    }
};