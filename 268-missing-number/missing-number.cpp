class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,x=0;
        for(int i=0;i<nums.size();i++){
            x=x^i;
            x=x^nums[i];
        }
        x=x^(nums.size());
        return x;
    }
};