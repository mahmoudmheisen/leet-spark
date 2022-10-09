class Solution {
private:
    void swap(vector<int>& arr, int pos1, int pos2, vector<string>& arr2){
        int temp1;
        string temp2;
        temp1 = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp1;
        temp2 = arr2[pos1];
        arr2[pos1] = arr2[pos2];
        arr2[pos2] = temp2;
    }

    int partition(vector<int>& arr, int l, int h, int p, vector<string>& arr2){
        int i = l;
        int j = l;
        while( i <= h){
            if(arr[i] < p){
                i++;
            }
            else{
                swap(arr,i,j, arr2);
                i++;
                j++;
            }
        }
        return j-1;
    }

    void q_sort(vector<int>& arr, int l, int h, vector<string>& arr2) {
        if(l >= h) return;
        
        int p = partition(arr, l, h, arr[h], arr2);
        q_sort(arr, l, p-1, arr2);
        q_sort(arr, p+1, h, arr2);
    }

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        q_sort(heights, 0, heights.size()-1, names);
        
        return names;
    }
};