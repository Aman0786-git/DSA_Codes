// Longest Palindromic Substring

#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    int getLen(string str, int left, int right)
    {
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string str)
    {
        int start = 0, end = 0;

        for (int i = 0; i < str.length(); i++)
        {

            int l1 = getLen(str, i, i);
            int l2 = getLen(str, i, i + 1);
            int l = max(l1, l2);
            if (end - start + 1 < l)
            {
                start = (l == l1) ? i - (l / 2) : (i - l / 2) + 1;
                end = i + l / 2;
            }
        }
        return str.substr(start, end - start + 1);
    }
};