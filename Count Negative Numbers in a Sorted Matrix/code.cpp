// problem link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
// Bruteforce solution O(n^2)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
   // grid.size() calculating outer vector size
        int row=grid.size(), col= grid[0].size(); 
        int cnt=0;
        for(int i=0; i<row; i++) {

            for(int j=0; j<col; j++) {
                if(grid[i][j]<0) cnt++;
            }

        }
        return cnt;
    }
};

// optimal solution O(m+n)
class Solution {
public:
int countNegatives(vector<vector<int>>& grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    int count = 0;
    
    int row = 0;
    int col = columns - 1;
    
    while (row < rows && col >= 0) {
        if (grid[row][col] < 0) {
            count += (rows - row);  // Increment count by the number of remaining rows
            col--;
        } else {
            row++;
        }
    }
    
    return count;
  }
   
};