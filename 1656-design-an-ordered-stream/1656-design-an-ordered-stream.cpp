class OrderedStream {
public:
    int size;
    map<int, string> m;
    int ptr;
    OrderedStream(int n) {
        size = n;
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        m[idKey] = value;
        
        vector<string> vec;
        for(int i = ptr; i <= size; i++) {
            if(m[ptr] != "") {vec.push_back(m[ptr]); ptr++;}
            else break;
        }
        
        return vec;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */