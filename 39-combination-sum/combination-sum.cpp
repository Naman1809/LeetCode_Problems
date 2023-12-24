class Solution {
public:
void helper(int i, vector<int>&nums, int target,vector<vector<int>>&ans,vector<int>res){
   
    if(i>nums.size()-1){
        if(target==0){
            ans.push_back(res);
            return;
        }
        return;
    }
    if(nums[i]<=target){

    res.push_back(nums[i]);
    helper(i,nums,target-nums[i],ans,res);
    res.pop_back();
    }
    helper(i+1,nums,target,ans,res);


}

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     vector<vector<int>>ans;
     vector<int>res;
     helper(0,nums,target,ans,res);
     return ans;
    }
};