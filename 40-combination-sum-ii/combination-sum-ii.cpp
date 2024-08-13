class Solution {
public:
void helper(vector<vector<int>>&ans, vector<int>&ds, int ind, int n, vector<int>&arr, int target){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int j=ind;j<n;j++){
        if(j!=ind&&arr[j]==arr[j-1])continue;
        if(arr[j]>target)break;
        ds.push_back(arr[j]);
        helper(ans,ds,j+1,n,arr,target-arr[j]);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        helper(ans,ds,0,n,arr,target);
        return ans;
    }
};