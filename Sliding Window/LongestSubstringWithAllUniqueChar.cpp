//Lenght of longest substring with all repeating characters


int lengthOfLongestSubstring(string s)
{
	int n = s.length();
	int r = 0, l = 0, ans = 0;
	vector<int>hash(128, -1);

	while (r < n) {
		if (hash[s[r]] >= l) {
			l = hash[s[r]] + 1;
		}
		ans = max(ans, r - l + 1);
		hash[s[r]] = r;
		r++;
	}
	return ans;
}