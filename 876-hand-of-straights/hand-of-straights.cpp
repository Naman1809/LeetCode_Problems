class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int i=0,j=0;
        int group =0;
        if(hand.size()%groupSize!=0) return false;
         unordered_map<int,int>m;
        for(int i=0;i<hand.size();i++) {
            m[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
           while(i<hand.size()) {

            int count=0,curr=hand[i];
        while(count<groupSize && m.find(curr)!=m.end()) {
                if(m[curr]==1) {
                    m.erase(curr);
                }
                
                else {
                    m[curr]--;
                }
                
                count++;
                
                curr++;
            }
            
            if(count==groupSize) {
                group++;
            }
            
            i++;
        }
        
        return group==hand.size()/groupSize;
}
};