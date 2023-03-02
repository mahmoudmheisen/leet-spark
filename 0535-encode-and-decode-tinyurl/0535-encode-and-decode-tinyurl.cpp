class Solution {
private:
    unordered_map<string, string> db;
    int uniqueCode = 1024;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(this->uniqueCode);
        this->uniqueCode++;
        
        db[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));