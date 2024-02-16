class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        vector<int>heap;
        for(auto it:arr) mp[it]++;

        for(auto it :mp) heap.push_back(it.second);
        make_heap(begin(heap),end(heap),greater<int>());
        while(k>0){
            k-=heap.front();
            pop_heap(begin(heap), end(heap), greater<int>());
            if(k>=0)heap.pop_back();
        }
        return heap.size();
    }
};