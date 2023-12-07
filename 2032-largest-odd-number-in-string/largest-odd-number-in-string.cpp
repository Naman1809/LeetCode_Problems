class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int a=-1;
        for( int i=num.size()-1;i>=0;i--){
if((num[i]-'0')%2){
    a=i;
    break;
}
        }
       if(a<0)return ans;
       else return num.substr(0,a+1); 
       
    }
};