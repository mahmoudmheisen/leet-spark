split function:
```
private:
vector<string> split(string s, char sep) {
vector<string> vec;
string word = "";
for(char c : s) {
if(c == sep) {
vec.push_back(word);
word = "";
} else {
word += c;
}
}
vec.push_back(word);
return vec;
};
```