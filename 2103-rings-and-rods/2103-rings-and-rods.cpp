class Solution {
public:
    int countPoints(string rings) {
      int count = 0;
      map<int, vector<int>> m;
      
      int n = rings.size() / 2;
      if (n < 3) return 0;
      
      for (int i = 0; i <= 9; i++) {
        m[i] = {0, 0, 0};
      }
      
      for (int i = 0; i < n; i++) {
        if (rings[i*2] == 'R') m[rings[i*2 + 1] - '0'][0] += 1;
        if (rings[i*2] == 'G') m[rings[i*2 + 1] - '0'][1] += 1;
        if (rings[i*2] == 'B') m[rings[i*2 + 1] - '0'][2] += 1;
      }
      
      for (int i = 0; i <= 9; i++) {
        if (m[i][0] && m[i][1] && m[i][2]) count++;
      }
      
      return count;
    }
};