class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> ht;
        ht['('] = ')';
        ht['{'] = '}';
        ht['['] = ']';

        for (char ch : s) {
            if (ht.count(ch)) {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if (ht[top] != ch) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};