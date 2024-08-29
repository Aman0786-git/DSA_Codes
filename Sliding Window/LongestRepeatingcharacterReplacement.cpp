int characterReplacement(string s, int k) {
	int i = 0, j = 0, n = s.length(), mxLen = 0, mxFreq = 0;
	unordered_map<char, int>mp;
	while (j < n) {
		mp[s[j]]++;
		mxFreq = max(mxFreq, mp[s[j]]);
		if ((j - i + 1) - mxFreq <= k) {
			mxLen = max(mxLen, j - i + 1);
		}
		else if ((j - i + 1) - mxFreq > k) {
			mp[s[i]]--;
			// if (mp[s[i]] == 0)mp.erase(mp[s[i]]);
			i++;
		}
		j++;
	}

	return mxLen;
}