class Solution {
public:
    long long maximumHappinessSum(vector<int>& sum, int k) {
        sort(sum.begin(),sum.end());
        int a=0;
        long long ans =0;
        int n = sum.size()-1;
        while(k--){
            int rem = sum[n]-a;
            if(rem<0)return ans;
            ans+=rem;
            n--;
            a++;
        }
        return ans;
    }
};