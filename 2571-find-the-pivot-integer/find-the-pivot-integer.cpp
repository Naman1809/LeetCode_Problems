class Solution {
public:
    int pivotInteger(int n) {
        int sum = ((n)*(n+1))/2;
        int currsum=0;
        for(int i=1;i<=n;i++){
            currsum+=i;
            sum-=(i-1);
            if(currsum == sum)return i;
        }
        return -1;
    }
};