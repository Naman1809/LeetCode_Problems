class Solution {
public:
    void helper(vector<int>&nums, int i, vector<int>&v, vector<vector<int>>&ans)
    {
        ans.push_back(v);
        for(int j=i;j<nums.size();j++){
            v.push_back(nums[j]);
            helper(nums,j+1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(nums,0,v,ans);
        return ans;
    }

};