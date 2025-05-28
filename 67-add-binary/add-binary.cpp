class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        char curry = '0';
        int aPointer = a.length() - 1;
        int bPointer = b.length() - 1;

        while (aPointer >= 0 && bPointer >= 0) {
            char currentCurry = '0';
            char sum = sumBinaryChars(a[aPointer], b[bPointer], currentCurry);

            
            sum = sumBinaryChars(sum, curry, curry);
            curry = sumBinaryChars(currentCurry, curry, curry);
            res = sum + res;

            aPointer--;
            bPointer--;
        }

        while (aPointer >= 0) {
            char sum = sumBinaryChars(a[aPointer], curry, curry);
            res = sum + res;
            aPointer--;
        }

        while (bPointer >= 0) {
            char sum = sumBinaryChars(b[bPointer], curry, curry);
            res = sum + res;
            bPointer--;
        }

        return curry == '1' ? curry + res : res;
    }

    char sumBinaryChars(char a, char b, char& curry) {
        char sum = '0';
        if (a == '0' && b == '0') {
            curry = '0';
            sum = '0';
        } else if ((a == '1' && b == '0') || (a == '0' && b == '1')) {
            curry = '0';
            sum = '1';
        } else if (a == '1' && b == '1') {
            curry = '1';
            sum = '0';
        }

        return sum;
    }
};