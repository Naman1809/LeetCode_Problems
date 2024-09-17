class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]+1)cnt++;
        }
        vector<int>ans;
        int j = k, i=1;
        while(j<n){
            if(cnt == k-1)ans.push_back(nums[j-1]);
            else ans.push_back(-1);

            if(nums[i-1] + 1 == nums[i])cnt--;
            if(nums[j-1]+1==nums[j])cnt++;
            j++;
            i++;
        }
        if(cnt==k-1)ans.push_back(nums[n-1]);
        else ans.push_back(-1);
        return ans;
    }
};