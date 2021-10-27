void toposortDFS(int node,vector<int>&vis,vector<int>adj[],stack<int>&st)
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			toposortDFS(it,vis,adj,st);
		}
	}
	st.push(node);

}
//                                                  TOPOSORT BFS(KHAN'S ALGORITHM)

void topoSortBFS(int n)//KHAN'S ALGORITHM
{
	vi indegree(n,0);
	for(int i=0;i<n;i++)
	{
		for(auto it:adj[i])
		{
			indegree[it]++;
		}
	}

	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int node=q.front();
		cout<<node<<" ";
		q.pop();
		for(auto it:adj[node])
		{
			indegree[it]--;
			if(indegree[it]==0)
			{
				q.push(it);
			}
		}
	}

	
}