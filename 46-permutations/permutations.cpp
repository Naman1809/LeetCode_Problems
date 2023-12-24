class Solution {
public:
// void helper(map<int,int>&mp, vector<int>&nums,vector<vector<int>>&ans,vector<int>&res){
//     if(res.size()==nums.size()){
//         ans.push_back(res);
//         return;
//     }
//     for(int i=0;i<nums.size();i++){
//         if(!mp[nums[i]]){
//             mp[nums[i]]=1;
//             res.push_back(nums[i]);
//             helper(mp,nums,ans,res);
//             mp[nums[i]]=0;
//             res.pop_back();
//         }
//     }


// }
void helper(int i, vector<int>&nums,vector<vector<int>>&ans,vector<int>&res){
if(i==nums.size()){
    ans.push_back(res);
    return;
}
for(int j=i;j<nums.size();j++){
    swap(nums[j],nums[i]);
    res.push_back(nums[i]);
    helper(i+1,nums,ans,res);
    res.pop_back();
    swap(nums[j],nums[i]);
    
}
}
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>res;
       map<int,int>mp;

    //    for(int i=0;i<nums.size();i++){
    //    mp[nums[i]]=0;
    //    } 
        //    helper(mp,nums,ans,res);
        helper(0,nums,ans,res);
           return ans;
    }
};