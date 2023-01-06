#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& arr) {
        

        int row=arr.length();
        int col=arr[0].length();
        int count=0;
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row-1;j++)
            {
                if(arr[j][i]>arr[j+1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;

    }
};