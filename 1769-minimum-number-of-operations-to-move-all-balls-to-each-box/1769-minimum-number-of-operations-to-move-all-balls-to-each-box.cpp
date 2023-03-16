class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ret(boxes.size(), 0);
        vector<int> idx;
        int leftSum = 0, rightSum = 0;
        int count = 0;
        
        for (int i = 1; i < boxes.size(); i++) {
            count += (boxes[i-1]-'0');
            leftSum = leftSum + count;
            cout << leftSum << " ";
            ret[i] = leftSum;
        }

        count = 0;
        for (int i = boxes.size()-2; i >= 0 ; i--) {
            count += (boxes[i+1]-'0');
            rightSum = rightSum + count;
            cout << rightSum << " ";
            ret[i] += rightSum;
        }
        
        return ret;
    }
};