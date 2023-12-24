class Solution {
public:
void helper(map<int,int>&mp, vector<int>&nums,vector<vector<int>>&ans,vector<int>&res){
    if(res.size()==nums.size()){
        ans.push_back(res);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!mp[nums[i]]){
            mp[nums[i]]=1;
            res.push_back(nums[i]);
            helper(mp,nums,ans,res);
            mp[nums[i]]=0;
            res.pop_back();
        }
    }


}
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>res;
       map<int,int>mp;

       for(int i=0;i<nums.size();i++){
       mp[nums[i]]=0;
       } 
           helper(mp,nums,ans,res);
           return ans;
    }
};