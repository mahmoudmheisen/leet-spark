class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.length();
        int m = b.length();
        int zeroBits = abs(n - m);

        for (int i = 0; i < zeroBits; i++) {
            if (m < n)
                b = "0" + b;
            else
                a = "0" + a;
        }

        int c = 0;

        for(int i = a.length()-1; i >=0; i--) {
            int s1 = a[i] - '0';
            int s2 = b[i] - '0';

            int sum = s1 + s2 + c;
            c = sum / 2;
            sum %= 2;

            res = to_string(sum) + res;
        }

        return c ? to_string(c) + res : res;
    }
};