/*

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and
6, i.e., 5+17=22.

*/
int cutRod(int price[], int n) {
    //code here
    //assigning dp table t with 0th row nd col as 0;
    vector<vector<int>>t(n + 1, vector<int>(n + 1, 0));
    //creating len vector for length of rod
    vector<int>len(n);
    iota(len.begin(), len.end(), 1);


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (len[i - 1] <= j)
            {
                t[i][j] = max(
                              price[i - 1] + t[i][j - len[i - 1]],//taking the ele and t[i] for repeat
                              t[i - 1][j]   // discarding the ele
                          );
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][n];
}