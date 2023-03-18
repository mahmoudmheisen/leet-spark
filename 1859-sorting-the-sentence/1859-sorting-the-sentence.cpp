class Solution {
private:
    vector<string> split(string s, char sep) {
        vector<string> vec;
        string word = "";
        
        for(char c : s) {
            if(c == sep) {
                vec.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        vec.push_back(word);
        
        return vec;
    };

public:
    string sortSentence(string s) {
        vector<string> vec;
        string ret = "";
        
        vec = split(s, ' ');

        sort(vec.begin(), vec.end(), [&](string r1, string r2) {
            return r1[r1.size()-1] < r2[r2.size()-1];
        });
        
        
        for(string w : vec) {
            w.pop_back();
            ret += w + ' ';
        }
        ret.pop_back();
        
        return ret;
    }
};
