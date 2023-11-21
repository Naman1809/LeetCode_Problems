class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int mod= 1e9+7;
        int count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            string s= to_string(nums[i]);
            reverse(s.begin(),s.end());
            int k= stoi(s);
            nums[i]=nums[i]-k;
            if(mp.find(nums[i])!=mp.end()){
                count = (count % mod + mp[nums[i]]%mod)%mod;
                // count+=mp[nums[i]]%mod;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};