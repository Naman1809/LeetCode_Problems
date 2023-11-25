class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n= nums.size();
        vector<int>suff(n,0),pref(n,0);
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=nums[i]+suff[i+1];
        }
        vector<int>ans;
        ans.push_back(suff[0]-n*nums[0]);
        for(int i=1;i<n-1;i++){
            int left = i*nums[i] -pref[i-1] ;
            int right = suff[i] - (n-i)*nums[i];
            ans.push_back(left+right);
        }
        ans.push_back(n*nums[n-1]-pref[n-1]);

        return ans;
    }
};