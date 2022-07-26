class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        
        int i = 0;
        for(int num: indices) {
            str[num] = s[i++];
        }
        
        return str;
    }
};