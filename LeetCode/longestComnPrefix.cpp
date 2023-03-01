class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            char chr = strs[0][i];

            bool match = true;

            for (int j = 1; j < n; j++ ) {
                if (strs[j].size() < i || chr != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            if (match == false)break;
            else
                ans.push_back(chr);
        }
        return ans;
    }
};