/*https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/*/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>t(c + 2, vector<int>(c + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j)continue;
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + t[i][ind - 1] + t[ind + 1][j];
                    mini = min(cost, mini);
                }
                t[i][j] = mini;
            }
        }
        return t[1][c];
    }
};