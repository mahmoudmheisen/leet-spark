class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int word1Pointer = 0;
        int word2Pointer = 0;

        for (int i = 0; i < word1.size() + word2.size(); i++) {
            string currentWord = word1;
            int pointer = 0;
            if (i & 1) {
                if (word2Pointer < word2.size()) {
                    currentWord = word2;
                    pointer = word2Pointer++;
                } else {
                    currentWord = word1;
                    pointer = word1Pointer++;
                }
            } else {
                if (word1Pointer < word1.size()) {
                    currentWord = word1;
                    pointer = word1Pointer++;
                } else {
                    currentWord = word2;
                    pointer = word2Pointer++;
                }
            }
            mergedString += currentWord[pointer];
        }

        return mergedString;
    }
};
