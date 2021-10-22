void dfs(int node) {
	cout << node << " ";
	vis[node] = 1;

	// traverse for all adjacent nodes
	// and go in depth for reach
	/// {2, 7, 9}
	for(auto it: adj[node]) {
		if(vis[it] == 0) {
			dfs(it);
		}
	}
}