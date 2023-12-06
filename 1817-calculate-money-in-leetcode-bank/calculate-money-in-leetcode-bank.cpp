class Solution {
public:
    int totalMoney(int n) {
        if(n<=7) return (n*(n+1))/2;

    return (n/7)*28 + (((n/7-1)*(n/7))/2)*7 + ((n%7)*(n%7+1))/2 + (n%7)*(n/7); 
    }
};