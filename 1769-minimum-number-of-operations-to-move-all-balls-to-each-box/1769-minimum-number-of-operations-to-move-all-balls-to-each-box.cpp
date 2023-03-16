class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        vector<int> idx;
        
        for(int i = 0; i < boxes.size(); i++) {
            if(boxes[i] == '1') idx.push_back(i);
        }
        
        for(int i = 0; i < boxes.size(); i++) {
            int b = boxes[i] - '0';
            int sum = 0;
            for(int s : idx) {
                sum += abs(s - i);
            }
            
            res.push_back(sum);
        }
        
        return res;
    }
};