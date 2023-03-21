class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size() - 1;
        long long c = 0;

        while (j <= n) {
            if (nums[j] == 0) {
                j++;
            } else {
                c +=(long long) (j - i) * (j - i + 1) / 2;
                i = j;
                i++;
                j++;
            }
        }
         c += (long long)(n - i + 1) * (n - i + 2) / 2;

        return c;
    }
};
