class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = "";
        int word1Pointer = 0;
        int word2Pointer = 0;

        for (int i = 0; i < max(word1.size(), word2.size()); i++) {
            if(i < word1.size())
                mergedString += word1[i];
            if(i < word2.size())
                mergedString += word2[i];
        }


        return mergedString;
    }
};
