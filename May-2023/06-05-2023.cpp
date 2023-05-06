#include<bits/stdc++.h>
using namespace std;

// This problem belongs subsequences so let's how we can print all the subsequences of an array.
// well if an array has distinct elements then total non-empty 2^n -1 subsequences are possible
// and if we will try some recursive way to solve this problem it's TC is O(2^n) which is exponential
// but wait let's see how recursion does this. for the sake of knowlege.
void subsequences(vector<int>& arr, int index, vector<int>& subseq) {
    if (index == arr.size()) {
        for (int x : subseq) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if(index==0){
        cout<<"epsilon"<<endl;
    }
    
    // Include the current element in the subsequence
    subseq.push_back(arr[index]);
    subsequences(arr, index+1, subseq);
    
    // Exclude the current element from the subsequence
    subseq.pop_back();
    subsequences(arr, index+1, subseq);
}

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; i++) {
            pows[i] = (pows[i-1] * 2) % MOD;
        }
        int l = 0, r = n-1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pows[r-l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
