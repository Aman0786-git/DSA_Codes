int longestKSubstr(string s, int k) {
    // your code here
    int j = 0, i = 0, ans = -1;
    map<char, int>mp;
    while (j < s.length()) {
        mp[s[j]]++;
        if (mp.size() < k)j++;
        else if (mp.size() == k) {
            ans = max(ans, j - i + 1);
            j++;
        }
        else {
            while (mp.size() > k)
            {
                mp[s[i]]--;

                if (mp[s[i]] == 0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}
