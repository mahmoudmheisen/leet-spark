class Solution {
public:
    string interpret(string command) {
        string str = "";
        int n = command.size();
        
        for (int i = 0; i < n; i++) {
            char c = command[i];

            if(c == 'G') str += "G";
            if(c == '(' && i+1 < n && command[i+1] == ')') str += "o";
            if(c == '(' && i+1 < n && command[i+1] == 'a') str += "al";
        }
        
        return str;
    }
};
