#include<bits/stdc++.h>
using namespace std;


// solution 1
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        // if Matrix is empty jsut return
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        // else calculate No. of rows and No. of columns
        int m = matrix.size();
        int n = matrix[0].size();

        // set top right left and buttom variables this is nothing but extream values
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        
        while (left <= right && top <= bottom) {
            // Traverse right
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            
            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

// solution 2


