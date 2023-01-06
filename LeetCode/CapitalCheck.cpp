#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool ans1 = true, ans2 = true, ans3 = true;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!isupper(word.at(i)))
            {
                ans1 = false;
                break;
            }
        }
        if (ans1)
            return ans1;

        for (int i = 0; i < n; i++)
        {
            if (!islower(word.at(i)))
            {
                ans2 = false;
                break;
            }
        }
        if (ans2)
            return ans2;

        if (!isupper(word.at(0)))
        {
            ans3 = false;
        }
        if (ans3)
        {

            for (int i = 1; i < n; i++)
            {
                if (!islower(word.at(i)))
                {
                    ans3 = false;
                    break;
                }
            }
        }
        if (ans3)
            return ans3;

        return false;
    }
};