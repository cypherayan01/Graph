void bfs(int node) {
	vis[node] = 1;
	queue<int> q;
	q.push(node);

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for(auto it : adj[node]) {
			if(!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}
}