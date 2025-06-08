class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int numberOfJewels = 0;
        unordered_set<char> uniqueJewels(jewels.begin(), jewels.end());

        for (char stone : stones) {
            if (uniqueJewels.count(stone))
                numberOfJewels++;
        }

        return numberOfJewels;
    }
};
