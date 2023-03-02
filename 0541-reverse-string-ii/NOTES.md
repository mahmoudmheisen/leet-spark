string str = s.substr(i, k);
reverse(str.begin(), str.end());
s.replace(i, k, str);