//                                                          DETECT CYCLE DFS

bool detectCycleDfs(int node,int parent,vector<int>&vis,vector<int> adj[])
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			if(detectCycleDfs(it,node,vis,adj)==true)
			{
				return true;
			}
		}
		else if(it!=parent){
			return true;
		}
	}
	return false;

}

//                                                   DETECT CYCLE BFS

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

//                                                   DETECT CYCLE DIRECTED GRAPH  DFS

bool detectCycleDGdfs(int node, vector<int>&vis,vector<int>&pathvis,vector<int>adj[])
{
	vis[node]=1;
	pathvis[node]=1;

	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			if(detectCycleDGdfs(it,vis,pathvis,adj)==true)
			{
				return true;
			}
		}
		else if(pathvis[it]==1)return true;
	}
	pathvis[node]=0;
	return false;
}