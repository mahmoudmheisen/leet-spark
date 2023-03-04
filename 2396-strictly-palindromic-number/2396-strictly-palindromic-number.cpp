class Solution {
private:
    string toBase(int n, int b) {
        string str = "";
        
        while(n > 0) {
            str += to_string(n % b);
            n /= b;
        }
        
        return str;
    }
    
    bool isPalindrom(string s) {
        bool res = true;
        int l = 0, r = s.size()-1;
        
        while(l < r) {
            if (s[l++] != s[r--]) return false;
        }
        
        return res;
    }

public:
    bool isStrictlyPalindromic(int n) {
        bool res = true;

        for(int i = 2; i <= n-2; i++) {
            if (!isPalindrom(toBase(n, i))) return false;
        }
        
        return res;
    }
};