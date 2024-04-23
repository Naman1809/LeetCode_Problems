class Solution {
public:
    vector<vector<int>> G;
	vector<bool> seen;
    vector<int> dfs(int i) {
		// longestPath will hold longest path found, starting from any of adjacent nodes of i
        vector<int> longestPath, path;
        seen[i] = true;                            // mark as visited to avoid loop
        for(auto adj : G[i])                       // run DFS from each adjacent node to find longest path
            if(!seen[adj]) 
                if(size(path = dfs(adj)) > size(longestPath)) 
                    longestPath = move(path);      // avoids copying...more info below
        seen[i] = false;
		longestPath.push_back(i);                  // add i itself to longest path & we get the longest path starting at i
        return longestPath;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        G.resize(n); seen.resize(n);
        for(auto& E : edges) 
            G[E[0]].push_back(E[1]), 
            G[E[1]].push_back(E[0]);
        auto path = dfs(dfs(0)[0]);                // 1st DFS from arbitrary node(0 in this case) & another DFS from furthest node returned by 1st DFS
        if(size(path) & 1)                         // 1 mid-node when path length is odd, otherwise 2
		    return {path[size(path)/2]};           
        return {path[size(path)/2], path[size(path)/2-1]};
    }
};