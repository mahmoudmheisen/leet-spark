class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        int maxBalloons = INT_MAX;
        unordered_map<char, int> processed;
        unordered_map<char, int> occurance;

        for (char character : text) {
            if (occurance.count(character))
                occurance[character]++;
            else
                occurance[character] = 1;
        }

        for (char character : target) {
            if (!processed.count(character)) {
                maxBalloons = min(maxBalloons, occurance[character]);
                processed[character] = 1;
            } else {
                processed[character]++;
                maxBalloons =
                    min(maxBalloons, occurance[character] / processed[character]);
            }
        }

        return maxBalloons;
    }
};