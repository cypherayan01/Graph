bool cycleDetectBfs(int node,vector<int>&vis,vector<int>adj[])
{
	vis[node]=1;
	queue<pair<int,int>> q;
	q.push({node,0});
	while(!q.empty())
	{
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				q.push({it,node});
				vis[it]=1;
			}
			else if(it!=parent)
			{
				return true;
			}
		}

	}
	return false;

}
