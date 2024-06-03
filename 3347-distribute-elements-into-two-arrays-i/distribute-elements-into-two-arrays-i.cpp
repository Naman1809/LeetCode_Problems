class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int i=0;
        int j=1;
          vector<int> nums1;
        vector<int> nums2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        for(int k=2;k<nums.size();k++){
            if(nums[i]>nums[j]){
                nums1.push_back(nums[k]);
                i=k;
            }else{
                nums2.push_back(nums[k]);
                j=k;
            }
        }
        for(int k=0;k<nums2.size();k++){
            nums1.push_back(nums2[k]);
        }
        return nums1;

    }
};