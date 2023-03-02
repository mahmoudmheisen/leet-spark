class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string word = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') word = s[i] + word;
            else {
                str += word + " ";
                word = "";
            }
        }
        str += word;


        return str;
    }
};