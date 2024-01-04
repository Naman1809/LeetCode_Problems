class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==1)return -1;
            else if(it.second%3==1||it.second%3==2){
                ans++;
            }
            ans+=it.second/3;
        }
        return ans;
    }
};