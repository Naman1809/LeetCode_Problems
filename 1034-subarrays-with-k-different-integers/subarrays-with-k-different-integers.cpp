class Solution {
public:
int helper(vector<int>&nums, int k){
    if(k<0)return 0;
    unordered_map<int,int>mp;
    int i=0,j=0,n=nums.size(),ans=0;
    while(j<n){
        mp[nums[j]]++;
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};