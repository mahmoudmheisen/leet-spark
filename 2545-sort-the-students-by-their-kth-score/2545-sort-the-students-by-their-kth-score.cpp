class Solution {
private:
    class MyComparator {
        private:
            int _k = 0;
        
        public:
            MyComparator(int k) : _k(k) {};
            bool operator() (vector<int> r1, vector<int> r2) {
                return r1[_k] > r2[_k];
            }
    };
    
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {   
        MyComparator comp(k);
        sort(score.begin(), score.end(), comp);
        
        return score;
    }
};