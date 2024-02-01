class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        bool f=true;
        for(int i=0;i<nums.size()-2;i+=3){
            if(nums[i+1]-nums[i]>k||(nums[i+2]-nums[i])>k){
                return {};
            }
            else{
                 vector<int>ans;
                 ans.push_back(nums[i]);
                                  ans.push_back(nums[i+1]);
                 ans.push_back(nums[i+2]);
                 v.push_back(ans);
            }
        }
     
            return v;
        
    }
};