class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
   map<int,int>mp;
int maxi=0;
        for(int i=0;i<nums.size();i++){
          maxi=max(maxi,++mp[nums[i]]);
        }
        vector<vector<int>>ans(maxi);

        for(int i=0;i<nums.size();i++){
            ans[mp[nums[i]]-1].push_back(nums[i]);
            mp[nums[i]]--;

        }
        // while(mp.size()>0){
        //     vector<int>res;
        //     for(auto it:mp){
        //         cout<<it.first<<" "<<it.second<<endl;
        //         res.push_back(it.first);
        //         mp[it.first]--;
        //         if(mp[it.first]==0){
        //             mp.erase(it.first);
        //         }
        //     }
        //     // cout<<res[0];
        //     ans.push_back(res);
        // }
        return ans;
    }
};