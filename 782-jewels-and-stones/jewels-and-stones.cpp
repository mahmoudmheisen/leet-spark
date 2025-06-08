class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int numberOfJewels = 0;
        set<char> uniqueJewels;

        for (int i = 0; i < jewels.length(); i++) {
            uniqueJewels.insert(jewels[i]);
        }

        for (int i = 0; i < stones.length(); i++) {
            if (uniqueJewels.count(stones[i]))
                numberOfJewels++;
        }

        return numberOfJewels;
    }
};
