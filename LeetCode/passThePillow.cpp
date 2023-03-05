class Solution {
public:
	int passThePillow(int n, int time) {
		int ans = 1;
		bool flg = true;
		while (time--) {
			if (flg)ans++;
			else
				ans--;

			if (ans == n || ans == 1)flg = !flg;

		}
		return ans;
	}
};