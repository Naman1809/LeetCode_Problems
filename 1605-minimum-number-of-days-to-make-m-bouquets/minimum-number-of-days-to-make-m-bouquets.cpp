class Solution {
public:
bool helper(long long int mid, vector<int>&A, int &m, int &k){
    int ans=0;
    int total=0;
    int n=A.size();
    for(int i=0;i<A.size();i++){
        if(A[i]<=mid)total++;

        else{
            if(total>=k){
                ans++;
            }
            total=0;
        }
        if(total>=k){
            ans++;
            total=0;
        }
    }
    if(total>=k)ans++;

    return (ans>=m);
}


    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int low=0,high=0;
        for(auto x: bloomDay){
            if(x>high)high=x;

        }

if((long long int )m*k>(long long int)bloomDay.size())return -1;
        while(low<high){
            long long int mid= low + (high-low)/2;
            if(helper(mid,bloomDay,m,k))high=mid;
            else low=mid+1;
        }
        return low;
    }
};