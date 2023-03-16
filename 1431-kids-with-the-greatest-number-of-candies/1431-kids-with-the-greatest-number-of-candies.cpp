class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;

        int maxNum = *max_element(candies.begin(), candies.end());

        for(int num : candies) {
            if(num + extraCandies >= maxNum) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};