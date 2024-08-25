int totalFruits(vector<int> &arr) {
	unordered_map<int, int>mp;
	int i = 0, j = 0;
	int total = INT_MIN;
	int n = arr.size();
	while (j < n) {
		mp[arr[j]]++;
		if (mp.size() < 2)j++;
		else if (mp.size() == 2) {
			total = max(total, j - i + 1);
			j++;
		}
		else if (mp.size() > 2) {
			while (mp.size() > 2)
			{
				mp[arr[i]]--;
				if (mp[arr[i]] == 0)mp.erase(arr[i]);
				i++;
			}
			j++;
		}
	}
	return total;
}