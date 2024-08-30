int solve(vector<int>& nums, int k) {

	int i = 0, j = 0, count = 0, sum = 0, n = nums.size();
	while (j < n) {
		if (sum < 0)return 0;
		sum += nums[j] % 2;
		while (sum > k) {
			sum -= nums[i] % 2;
			i++;
		}
		count += (j - i + 1);
		j++;
	}
	return count;

}
int numSubarraysWithSum(vector<int>& nums, int goal) {
	return solve(nums, goal) - solve(nums, goal - 1);
}
