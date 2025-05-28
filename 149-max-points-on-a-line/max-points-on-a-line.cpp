class Solution {
public:
    struct PairHash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    struct PairEqual {
        template <class T1, class T2>
        bool operator()(const pair<T1, T2>& lhs,
                        const pair<T1, T2>& rhs) const {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    };

    int maxPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            res = max(res, maxPointForFocal(i, points));
        }

        return res;
    }

    int maxPointForFocal(int idx, vector<vector<int>>& points) {
        unordered_map<pair<int, int>, int, PairHash, PairEqual> slopesHash;
        int maxPoints = 0;

        for (int i = 0; i < points.size(); i++) {
            if (i == idx)
                continue;
            pair<int, int> slope = getSlope(points[idx], points[i]);
            slopesHash[slope]++;
            maxPoints = max(maxPoints, slopesHash[slope]);
        }
        return maxPoints + 1;
    }

    pair<int, int> getSlope(vector<int> p1, vector<int> p2) {
        int rise = p2[1] - p1[1];
        int run = p2[0] - p1[0];

        if (run == 0) {
            return make_pair(1, 0);
        }

        int gcdValue = gcd(rise, run);
        return make_pair(rise / gcdValue, run / gcdValue);
    }

    int gcd(int a, int b) {
        while (b) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
};