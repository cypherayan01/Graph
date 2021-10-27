#include<bits/stdc++.h>

using namespace std;

#define int long long int 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define vi vector<int> 

vector<int> adj[1000005];
vector<int> vis[1000005];


//                                                   TRAVRSAL TECHNIQUE DFS
void dfs(int node,vector<int>&vis,vector<int> adj[])
{
	cout<<node<<" ";
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			dfs(it,vis,adj);
		}
	}
}
//                                                      TRAVRSAL TECHNIQUE BFS

void bfs(int node,vector<int>&vis,vector<int> adj[])
{
	vis[node]=1;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int node =q.front();
		q.pop();
		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				vis[it]=1;
				q.push(it);
			}
		}
	}
}

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
//                                                       TOPOSORT DFS

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


//                                                     SHORTEST PATH ALGORITHM   


//                                                         0/1 BFS

void dfszeroone(int source,int n)
{
	deque<pair<int,int>> dq;
	vector<int> dist(n,0);
	for(int i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[source]=0;
	dq.push_front({source,0});
	while(!dq.empty())
	{
		int node=dq.front().first;
		int wt=dq.front().second;
		for(auto it:adj[node])
		{
			int adjnode=it.first;
			int adjwt=it.second;
			if(dist[adjnode]>wt+adjwt)
			{
				dist[adjnode]=wt+adjwt;
				if(adjwt==0)
				{
					dq.push_front({adjnode,dist[adjnode]});
				}
				else{
					dq.pb({adjnode,dist[adjnode]});
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<dist[i]<<" ";
	}
}

//                                                   DIJKSTRA ALGORITHM

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

//                                           CREATE A GRAPH
void createGraph()
{
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<int> vis(n+1,0);
	vector<int> pathvis(n+1,0);
	for(int i=1;i<=m;i++)
	{		
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);//no need to for directed graph		
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i,vis,adj);
			bfs(i,vis,adj);
			cycleDetectBfs(i,vis,adj);
			detectCycleDfs(i,0,vis,adj);
			detectCycleDGdfs(i,vis,pathvis,adj);

		}
	}
}









































// void bfs(int node) {
// 	vis[node] = 1;
// 	queue<int> q;
// 	q.push(node);

// 	while(!q.empty()) {
// 		int node = q.front();
// 		q.pop();
// 		cout << node << " ";

// 		for(auto it : adj[node]) {
// 			if(!vis[it]) {
// 				vis[it] = 1;
// 				q.push(it);
// 			}
// 		}
// 	}
// }



