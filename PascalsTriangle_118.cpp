/*
Leetcode : #73 {https://leetcode.com/problems/pascals-triangle/description/}

....1     
...1.1
..1.2.1
.1.3.3.1

here n = 4
i.e Return the first 'n' rows of Pascal's Triangle
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            vector<int> v(i+1,1);
            for(int j = 1; j < i; j++) {
                v[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(v);
        }
        return ans;
    }

};