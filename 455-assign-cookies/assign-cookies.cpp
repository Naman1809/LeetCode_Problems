class Solution {
public:
    int findContentChildren(vector<int> &greed, vector<int> &sz) {
        int N=greed.size(),M=sz.size();
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int i=N-1,j=M-1,ans=0;
        while(i>=0&&j>=0){
            if(greed[i]<=sz[j]){
                ans++;
                i--;
                j--;
            }
            else {
                i--;
            }
        }
        return ans; 
    }
};