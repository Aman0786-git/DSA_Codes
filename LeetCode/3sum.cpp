#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;

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
void display_ans(vector<vector<int>> temp)
{
    for (auto triplet : temp)
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << "\n";
}
int main()
{
    vector<int> v = { -1, 0, 1, 2, -1, -4};
    display_ans(threeSum(v));
    return 0;
}