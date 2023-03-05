class Solution {
public:
    string reversePrefix(string word, char ch) {
        string sub = "";
        bool rev = true;
        
        for(int i = 0; i < word.size(); i++) {           
            if(rev) sub = word[i] + sub;
            else sub += word[i];
            
            if(word[i] == ch) {
                rev = false;
            }
        }
        
        return rev ? word : sub;
    }
};