class Solution {
public:
bool palindrome(long long n){
    string s=to_string(n);
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
long long calculate(vector<int>&nums,int n){
    long long cost =0;
    for(int i=0;i<nums.size();i++){
        cost+=(abs(nums[i]-n));
    }
    return cost;
}
long long greater(long long n){
    while(!palindrome(n)){
        n++;
    }
    return n;
}
long long smaller(long long n){
    while(!palindrome(n)){
        n--;
    }
    return n;
}
    long long minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid;
        if(n%2){
            mid=nums[n/2];
        }
        else{
            mid = (nums[n/2]+nums[(n+1)/2])/2;
        }
        long long great = greater(mid);
        long long small = smaller(mid);
            long long res1   =calculate(nums,great);
            long long res2   =calculate(nums,small);
    return min(res1,res2);
    }
};