class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int k=0;
        ans.push_back({intervals[0][0],intervals[0][1]});

            for(auto it:intervals){
                if(ans[k][1]>=it[0]){
                    ans[k][1]=max(ans[k][1],it[1]);
                }else{
                    ans.push_back({it[0],it[1]});
                    k++;
                }
            }
return ans;
    }
};