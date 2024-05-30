/*
Leetcode : #73 {https://leetcode.com/problems/set-matrix-zeroes/description/}

1 1 1    1 0 1
1 0 1 -> 0 0 0
1 1 1    1 0 1
i.e If an element is 0, Set it's entire row & columns to 0 
*/
// #include <algorithm>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>& matrix, int r, int c, int rd, int cd, vector<vector<bool>>& visited) {
        if(r>=0 && r<matrix.size() && c>=0 && c<matrix[0].size() && (!visited[r][c] || matrix[r][c] == 0)) {
            if(matrix[r][c] != 0)
                visited[r][c] = true;
            matrix[r][c] = 0;
            dfs(matrix, r + rd,c + cd, rd, cd, visited);
        }   
    }



    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int i=0; i < r; i++) {
            for(int j=0; j < c; j++) {
                if(matrix[i][j] == 0 && !visited[i][j]){
                    visited[i][j] = true;
                    for(auto& d : dir) {
                        dfs(matrix, i+d[0], j+d[1], d[0], d[1], visited);
                    }
                }   
            }
        }
    }

    void main() {
        vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
        setZeroes(matrix);

        for(int i=0; i< matrix.size(); i++) {
            for(int j=0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};