/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<vector<int>>res;
        int n = num.size();
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || (i > 0 && num[i] != num[i - 1])) {

                int low = i + 1, high = n - 1 , sum = 0 - num[i];
                while (low < high)
                {
                    if (num[low] + num[high] == sum)
                    {
                        res.push_back({num[i], num[low], num[high]});
                        while (low < high && num[low] == num[low + 1])low++;
                        while (low < high && num[high] == num[high - 1])high--;

                        low++;
                        high--;
                    }
                    else if ( num[low] + num[high] < sum)low++;
                    else high--;
                }
            }
        }
        return res;

    }
};