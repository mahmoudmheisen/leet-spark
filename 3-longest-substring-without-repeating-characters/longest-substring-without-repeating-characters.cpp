class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_map<char, int> ht;
        int left = 0, right = 0;

        while(right < s.length()) {
            if(ht.count(s[right]) && ht[s[right]] >= left) {
                left = ht[s[right]] + 1;
            }
            maxLength = max(maxLength, right-left+1);
            ht[s[right]] = right;
            right++;
        }

        return maxLength;
    }
};