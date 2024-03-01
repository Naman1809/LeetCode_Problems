class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n= s.size();
        // if(s[n-1]=='0'){
        //     swap(s[n-1],s[n-2]);
        //     return s;
        // }
        // else{
        //     int z=0,o=-1;
        //     for( int i=0;i<n;i++){
        //         if(s[i]=='0'){
        //             z=i;
        //             break;
        //         }
        //     }
        //       for( int i=z;i<n;i++){
        //         if(s[i]=='1'){
        //             o=i;
        //             break;
        //         }
        //     }
        //     if(o==n-1)return s;
        //     if(o==-1){
        //         s[z-1]=0;
        //         s[n-1]=1;
        //         return s;
        //     }
        //     swap(s[z],s[o]);
        //     return s;
        // }
        int o=0,z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')z++;
            else o++;
        }
        string str="";
        o--;
        for(int i=0;i<o;i++){
            s[i]=1+'0';
        }
        for(int i=o;i<n;i++){
            s[i]=0+'0';
        }
        s[n-1]=1+'0';
        return s;
      
        
    }
};