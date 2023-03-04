class Solution {
private:
    string toStr(vector<string>& word) {
        int n = word.size();
        string str = "";
        for(int i = 0; i < n; i++) {
            str += word[i];
        }
        
        return str;
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return toStr(word1) == toStr(word2);
    }
};