class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int word1Pointer = 0;
        int word2Pointer = 0;

        for (int i = 0; i < min(word1.size(), word2.size()); i++) {
            mergedString += word1[i];
            mergedString += word2[i];
        }

        if (word1.size() < word2.size()){
            mergedString += word2.substr(word1.size());
        } else {
            mergedString += word1.substr(word2.size());
        }

        return mergedString;
    }
};
