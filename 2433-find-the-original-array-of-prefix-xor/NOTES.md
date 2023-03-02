xor solution
​
use temp value instead of a for loop
​
vector<int> findArray(vector<int>& pref) {
vector<int> ret;
ret.push_back(pref[0]);
for(int i = 1; i < pref.size(); i++) {
int ans = pref[i];
for(int j = 0; j < i; j++) {
ans ^= ret[j];
}
ret.push_back(ans);
}
return ret;
}