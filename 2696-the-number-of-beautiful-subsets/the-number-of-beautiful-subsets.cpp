// class Solution {
// public:

// void helper(vector<int>&nums, unordered_map<int,int>&mp, int ind, int k, int &ans){
// //     if(ind==nums.size())ans++;
// //     else{
// //     if(!mp[nums[ind]-k]&&!mp[nums[ind]+k]){
// // mp[nums[ind]]++;
// // helper(nums,mp,ind+1,k,ans);
// // mp[nums[ind]]--;
// //     }
// //     helper(nums,mp,ind+1,k,ans);
// //     }
// ans++;
// for(int j=ind;j<nums.size();j++){
//     if(!mp[nums[ind]-k]&&!mp[nums[ind]+k]){
// mp[nums[ind]]++;
// helper(nums,mp,j+1,k,ans);
// mp[nums[ind]]--;
//      }
// }
// }
//     int beautifulSubsets(vector<int>& nums, int k) {
//      unordered_map<int,int>mp;
//      sort(nums.begin(),nums.end());
//         int n=nums.size();
//       int ans=0;
//       helper(nums,mp,0,k,ans);
//       return ans-1;
//     }
// };
class Solution {
public:
    
    int helper(vector<int>& nums, vector<int>& dp, int k, int i, int n) {
        if (i == n) return 0;
        
        int take = 0;
        
        int notTake = helper(nums,dp,k,i + 1,n);
        
        if (binary_search(dp.begin(), dp.end(), nums[i] - k) == 0)
        {
            dp.push_back(nums[i]);
            take = 1 + helper(nums,dp,k,i + 1,n);
            dp.pop_back();
        }
    
        return take + notTake;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp;
        
        return helper(nums,dp,k,0,n);
    }
};