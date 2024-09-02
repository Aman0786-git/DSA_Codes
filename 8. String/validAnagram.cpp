bool isAnagram(string s, string t) {
	int sLen = s.length();
	int tLen = t.length();
	if (sLen != tLen)return false;
	unordered_map<char, int>mp;
	for (int i = 0; i < sLen; i++) {
		mp[s[i]]++;
		mp[t[i]]--;
	}
	for (auto it : mp) {
		if (it.second != 0)return false;
	}
	return true;
}