class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        set<char> uniques;
        int left = 0, right = 0;

        while(right < s.length()) {
            while(uniques.count(s[right])) {
                uniques.erase(s[left]);
                left++;
            }
            maxLength = max(maxLength, right-left+1);
            uniques.insert(s[right]);
            right++;
        }

        return maxLength;
    }
};