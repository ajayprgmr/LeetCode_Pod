#include<bits/stdc++.h>
using namespace std;
// bruteforce solution TC : N*LOGN
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>ans;
    int n=nums.size();
    unordered_map <int,int> mpp;
    for(int i=0; i<n; i++) {
        mpp[nums[i]]++;
    }
    vector<pair<int,int>>v(mpp.begin(),mpp.end());
    sort(v.begin(), v.end(), [](pair<int,int>& a,  pair<int,int>& b) {
    return a.second > b.second;});
    for(int i=0;i<k;i++) {
        ans.push_back(v[i].first);
    }
      return ans;  
    }
};
// better approach

