class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even_mask = 0x55555555;
        int odd_mask = 0xaaaaaaaa;
        int evens = even_mask & n;
        int odds = odd_mask & n;
        int count_e = 0, count_o = 0;

        odds >>= 1;
        while (n > 0) {
            if (evens & 1)
                count_e++;
            if (odds & 1)
                count_o++;
            evens >>= 2;
            odds >>= 2;
            n >>= 2;
        }

        return {count_e, count_o};
    }
};