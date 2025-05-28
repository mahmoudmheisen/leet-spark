class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            res = max(res, maxPointForFocal(i, points));
        }

        return res;
    }

    int maxPointForFocal(int idx, vector<vector<int>>& points) {
        unordered_map<long long, int> slopesHash;
        int maxPoints = 0;

        for (int i = 0; i < points.size(); i++) {
            if (i == idx)
                continue;
            long long slope = getSlope(points[idx], points[i]);
            slopesHash[slope]++;
            maxPoints = max(maxPoints, slopesHash[slope]);
        }
        return maxPoints + 1;
    }

    long long getSlope(vector<int> p1, vector<int> p2) {
        int rise = p2[1] - p1[1];
        int run = p2[0] - p1[0];

        if (run == 0) {
            return (long long)(1) << 32;
        }

        int gcdValue = __gcd(rise, run);
        long long key = (long long)(rise / gcdValue) << 32 | (unsigned int)(run / gcdValue);

        return key;
    }
};