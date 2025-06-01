class Solution {
public:
    int index(char charactar) { return charactar - 'a'; }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> s_freq(26, 0), t_freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            int s_index = index(s[i]);
            int t_index = index(t[i]);
            s_freq[s_index]++;
            t_freq[t_index]++;
        }

        return s_freq == t_freq;
    }

    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length())
            return {};

        vector<int> anagrams;
        int windowSize = p.length();
        int left = 0;
        int right = windowSize - 1;

        while (right < s.length()) {
            string subStr = s.substr(left, windowSize);
            if(isAnagram(subStr, p)) {
                anagrams.push_back(left);
            }
            left++;
            right++;
        }

        return anagrams;
    }
};