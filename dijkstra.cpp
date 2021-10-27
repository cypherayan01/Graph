void dijkstra()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	int a,b,wt;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>wt;
		adj[a].pb({b,wt});
		adj[b].pb(mp(a,wt));
	}
	int source;cin>>source;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int>dist(n+1,INT_MAX);
	dist[source]=1;
	pq.push({0,source});
	while(!pq.empty())
	{
		int node=pq.top().second;
		int nodewt=pq.top().first;
		pq.pop();
		for(auto it:adj[node])
		{
			int nextnode=it.first;
			int nextwt=it.second;
			if(dist[nextnode]>nodewt+nextwt)
			{
				dist[nextnode]=nodewt+nextwt;
				pq.push({dist[nextnode],nextnode});
			}
		}

	}
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}

}