class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int m = pick.size();
        int ans=0;
        vector<vector<int>>mp(n,vector<int>(12,0));
        for(int i=0;i<m;i++){
            mp[pick[i][0]][pick[i][1]]++;
            if(mp[pick[i][0]][pick[i][1]]>mp[pick[i][0]][11]){
                mp[pick[i][0]][11]=mp[pick[i][0]][pick[i][1]];
            }
        }
        for(int i=0;i<n;i++){
            if(mp[i][11]>i)ans++;
        }
        return ans;
    }
};