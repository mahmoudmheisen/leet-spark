class Solution {
public:
    int hammingWeight(uint32_t n) {
      int ret = 0;
      string str = bitset<32>(n).to_string();

      for (char c : str) {
        if (c - '0') ret++;
      }
      
      return ret;
    }
};